cmake_minimum_required(VERSION 3.11)

# Set the project name
project(APIServer)

# preferred c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

# Function to download the libraries
include(FetchContent)

# Download asio
FetchContent_Declare(
  asio
  GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
  GIT_TAG master
)
FetchContent_GetProperties(asio)
if(NOT asio_POPULATED)
  FetchContent_Populate(asio)
  set(ASIO_INCLUDE_DIR ${asio_SOURCE_DIR}/asio/include CACHE INTERNAL "Path to Asio include directory")
endif()

# Download crow
FetchContent_Declare(
  crow
  GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
  GIT_TAG master
)
FetchContent_MakeAvailable(crow)

# Download libpqxx
FetchContent_Declare(
  libpqxx
  GIT_REPOSITORY https://github.com/jtv/libpqxx.git
  GIT_TAG master
)
FetchContent_GetProperties(libpqxx)
if(NOT libpqxx_POPULATED)
  FetchContent_Populate(libpqxx)
  add_subdirectory(${libpqxx_SOURCE_DIR} ${libpqxx_BINARY_DIR})
endif()

# include the libraries
include_directories(${asio_SOURCE_DIR}/asio/include ${crow_SOURCE_DIR}/include ${libpqxx_SOURCE_DIR}/include)

# Generate the build files for the server
add_executable(${PROJECT_NAME} Server.cpp)

# Overriding the location for the runtime output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Ensures the compiler can find include files for the downloaded libraries
target_include_directories(${PROJECT_NAME} PRIVATE ${asio_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${crow_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE pqxx)