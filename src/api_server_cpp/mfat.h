#pragma once

// standard libraries
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include <regex>
#include <fstream>
#include <iostream>
#include <string>
#include <deque>
#include <mutex>

// Non-standard libraries
#include <pqxx/pqxx>

namespace mfat
{

    /**
     * @brief Loads environment variables from a .env file
     *
     * @details
     *
     * The .env file is a simple text file with the following format:
     *
     * ```
     * KEY1=VALUE1
     * KEY2=VALUE2
     * ```
     *
     * This function will load the .env file and set the environment variables accordingly.
     *
     * @param string The path to the .env file
     *
     * @returns void
     */
    void load_dotenv(const std::string &path)
    {
        try
        {
            std::ifstream file(path);
            std::string line;
            while (std::getline(file, line))
            {
                size_t pos = line.find('=');
                if (pos != std::string::npos)
                {
                    std::string key = line.substr(0, pos);
                    std::string value = line.substr(pos + 1);
                    setenv(key.c_str(), value.c_str(), 1);
                }
            }
        }
        catch (...)
        {
            std::cerr << "Error while loading .env file." << std::endl;
        }
    }

    /**
     * @brief A class to handle database connections
     *
     * @details
     *
     * This class is used to handle database connections. It is a wrapper around the pqxx::connection class with some additional functionality.
     * It supports one connection per instance.
     *
     * @param pqxx::connection *c A pointer to a pqxx::connection object
     *
     * @returns void
     */
    class DatabaseConnection
    {
    private:
        std::unique_ptr<pqxx::connection> conn;
        std::mutex mtx;

    public:
        DatabaseConnection(std::unique_ptr<pqxx::connection> c) : conn(std::move(c))
        {
            if (!conn)
            {
                throw std::runtime_error("No valid database connection");
            }
            try
            {
                conn->prepare("select_statement", "SELECT * FROM test WHERE value = $1;");
            }
            catch (const pqxx::sql_error &e)
            {
                std::cerr << "SQL related error: " << e.what() << std::endl; // TODO @sec-rev remove log error
                throw;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Unspecified error in database connection" << std::endl;
                throw;
            }
        }
        // Default constructor
        DatabaseConnection() = default;

        pqxx::result selectIDFromTest(const std::string &value)
        {
            // use parameterized queries / prepared statements to prevent SQL injection attacks.
            std::lock_guard<std::mutex> lock(mtx); // ensure thread safety

            try
            {
                pqxx::work trans(*conn);

                pqxx::result res = trans.exec_prepared("select_statement", value);

                trans.commit();
                return res;
            }
            catch (const pqxx::sql_error &e)
            {
                std::cerr << "SQL related error: " << e.what() << std::endl; // TODO @sec-rev remove log error
                throw;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Unspecified error in database connection" << std::endl;
                throw;
            }
        }
    };

    /**
     * @brief A class to pool database connections for improved performance
     *
     * @details
     *
     * This class is used to pool database connections. It is a wrapper around the pqxx::connection class with some additional functionality.
     * A pool can be initialized with an arbitrary number of connections.
     *
     * @param int The number of connections to initialize the pool with
     *
     */
    class ConnectionPool
    {
    private:
        std::deque<std::unique_ptr<DatabaseConnection>> pool;
        std::mutex mtx;

    public:
        // Initialize the pool with 'n' connections
        ConnectionPool(int n)
        {
            for (int i = 0; i < n; i++)
            {
                char connectionCredentials[256];

                sprintf(connectionCredentials, "dbname=%s user=%s password=%s host=mfat-db-postgresql port=%s",
                        std::getenv("POSTGRES_DB"),
                        std::getenv("POSTGRES_USER"),
                        std::getenv("POSTGRES_PASSWORD"),
                        std::getenv("DB_POSTGRESQL_PORT_DOCKER"));

                std::unique_ptr<pqxx::connection> c(new pqxx::connection(connectionCredentials));

                pool.push_back(std::make_unique<DatabaseConnection>(std::move(c)));
            }
        }

        // Get a connection from the pool
        std::unique_ptr<DatabaseConnection> getConnection()
        {
            std::lock_guard<std::mutex> lock(mtx);

            if (pool.empty())
            {
                throw std::runtime_error("No available connections");
            }

            auto conn = std::move(pool.front());
            pool.pop_front();

            return conn;
        }

        // Return a connection to the pool
        void returnConnection(std::unique_ptr<DatabaseConnection> conn)
        {
            std::lock_guard<std::mutex> lock(mtx);
            pool.push_back(std::move(conn));
        }
    };
}
