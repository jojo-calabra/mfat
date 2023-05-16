
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

  // TODO set loglevel

  // Create a db connection pool with 10 connections
  mfat::ConnectionPool pool(10);

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

      CROW_LOG_INFO << "Connecting to database... "; //send a crow log message

      // Get a connection from the pool
      std::unique_ptr<mfat::DatabaseConnection> db = pool.getConnection();

      CROW_LOG_INFO << "Query selectIDFromTest... "; //send a crow log message

      // Use the connection
      pqxx::result res = db->selectIDFromTest(std::to_string(id));

      CROW_LOG_INFO << "Returning connection... "; //send a crow log message

      // Return the connection to the pool
      pool.returnConnection(std::move(db));

      // Check if result is empty, if so, return not found error
      if (res.empty())
      {
        x["error"] = "No data found for given id";
        return crow::response(404, x); // Send not found response
      }

      // Extract value from result
      x["value"] = res[0][0].as<int>(); // select value from resultset

      return crow::response(x); // Send response
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