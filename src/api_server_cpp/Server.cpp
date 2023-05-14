
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
// #include <grpcpp/grpcpp.h>
// #include <cryptopp/pwdbased.h>
// #include <cryptopp/sha.h>
// #include <cryptopp/hex.h>
// TODO add postgres
// TODO add redis https://github.com/cpp-redis/cpp_redis

// function stubs for later declaration
void load_dotenv(const std::string &path);

int main()
{
  load_dotenv("./.env"); // Load environment variables from .env file

  // TODO open postgres DB connection

  crow::SimpleApp app; // Create new server instance

  CROW_ROUTE(app, "/helloworld") // TODO remove hello world dummy Endpoint after container testing
  ([]
   {
      crow::json::wvalue x;
      x["message"] = "Hello, World!";
      return x; });

  // TODO Implement endpoints as specified in API reference (check the wiki, create issues)

  app.port(3000).multithreaded().run(); // Run the server on port 3000 and use multithreading

  return 0;
}

void load_dotenv(const std::string &path)
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