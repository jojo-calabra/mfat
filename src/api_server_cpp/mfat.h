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
        DatabaseConnection(std::unique_ptr<pqxx::connection> c)
            : conn(std::move(c))
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
}
