cmake_minimum_required(VERSION 3.11)

project(mfat)

# Set build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()


### The following section Builds the C++ API server

# Variable for the subdirectory/build directory
set(API_SERVER_CPP_SUBDIR ${CMAKE_CURRENT_SOURCE_DIR}/src/api_server_cpp)

# Copy projects main .env file to the subdirectory/build directory
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.env ${API_SERVER_CPP_SUBDIR}/build/.env COPYONLY)

# Add subdirectory and build the cmake project contained in it
add_subdirectory(${API_SERVER_CPP_SUBDIR})

