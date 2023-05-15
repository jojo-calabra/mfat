
// Protobuf & gRPC (C++ gRPC Server for cluster communication)
// crow (C++ REST/HTTP Server for API)
// openssl (for https)
// boost (for all kinds of uses, theres over 160 libraries included in boost)

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
/*
This project is configured for vscode. There paths to the included libraries are configured in the .vscode/c_cpp_properties.json file.
That means intellisense ERRORS CONCERNING LIBRARIES WILL DISAPPEAR ONCE THE PROJECT HAS BEEN BUILT FOR THE FIRST TIME.
The errors initially occur because these libraries are not included in the repository to allow for more flexibility in dependency management.
Our dependencies are resolved automatically by the CMake build system (as configured in the CMakeLists.txt files).
*/

#include "crow.h"
#include <pqxx/pqxx>
// #include <grpcpp/grpcpp.h>
// #include <cryptopp/pwdbased.h>
// #include <cryptopp/sha.h>
// #include <cryptopp/hex.h>
// TODO add redis https://github.com/cpp-redis/cpp_redis connector

// Project libraries
#include "mfat.h"

int main()
{
  mfat::load_dotenv(".env"); // Load environment variables from .env file

  int port = std::stoi(std::getenv("API_SERVER_CPP_PORT_DOCKER")); // Get port from environment variable and parse to int
  if (port < 0 || port > 65535)                                    // Check if port is in valid range
  {
    std::cerr << "Invalid port number: " << port << std::endl;
    return 1; // abort the server launch immediately
  }

  crow::SimpleApp app; // Create new server instance

  CROW_ROUTE(app, "/helloworld") // TODO remove hello world dummy Endpoint after container testing
  ([]
   {
      crow::json::wvalue x;
      x["message"] = "Hello, World!";
      return x; });

  // TODO Implement endpoints as specified in API reference (check the wiki, create issues)

  CROW_ROUTE(app, "/db-test/<int>") // TODO remove db test dummy Endpoint after container testing
  ([&](int id) -> crow::response    // I've added return type here to specify that we're returning a crow::response
   {
    crow::json::wvalue x;

    try
    {
      // Initialize database connection
      // Using sprintf and c-style char buffer. Consider using safer methods to avoid buffer overflow.
      char connectionCredentials[256];
      sprintf(connectionCredentials, "dbname=%s user=%s password=%s host=db-postgresql port=%s",
        std::getenv("POSTGRES_DB"),
        std::getenv("POSTGRES_USER"),
        std::getenv("POSTGRES_PASSWORD"),
        std::getenv("DB_POSTGRESQL_PORT_DOCKER"));

      std::unique_ptr<pqxx::connection> c(new pqxx::connection(connectionCredentials));
      
      mfat::DatabaseConnection db(std::move(c)); // Use the correct namespace

      // Query database
      pqxx::result res = db.selectIDFromTest(std::to_string(id));
      
      // Check if result is empty, if so, return error
      if (res.empty())
      {
        x["error"] = "No data found for given id";
        return crow::response(404, x);
      }

      // Extract value from result
      x["value"] = res[0][0].as<int>(); // adjust according to your table structure
      return crow::response(x);
    }
    catch (const std::exception &e)
    {
      // Handle errors
      x["error"] = e.what();
      return crow::response(500, x);
    } });

  try
  {
    app.port(port).multithreaded().run(); // Run the server on the specified port and enable multithreading
  }
  catch (...)
  {
    std::cerr << "Server error while starting server. Shutting down. " << std::endl;
    return 1; // abort the server launch immediately
  }

  return 0;
}