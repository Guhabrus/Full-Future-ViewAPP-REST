cmake_minimum_required(VERSION 3.2)
project(KMA_serve C CXX)
SET(EXAMPLE_BINARY "KMA_server")


find_package(Threads)
find_package(ZLIB)
find_package(Poco REQUIRED COMPONENTS Foundation Util Net XML JSON Crypto NetSSL)
find_package(CppKafka REQUIRED)
find_package(Boost COMPONENTS filesystem system program_options regex REQUIRED)

if(NOT ${Poco_FOUND})
    message(FATAL_ERROR "Poco C++ Libraries not found.")
endif()

if(NOT ${CppKafka_FOUND})
    message(FATAL_ERROR "Cppkafka C++ Libraries not found.")
endif()

if(NOT ${Boost_FOUND})
    message(FATAL_ERROR "Boost C++ Libraries not found.")
endif()


include_directories(${Poco_INCLUDE_DIRS})
include_directories(${GTEST_INCLUDE_DIRS})
include_directories("/usr/include/mysql")
include_directories("/usr/local/include/mysql")

include_directories(${Boost_INCLUDE_DIR})
include_directories("/home/maksim/Myfolder/CppKafka/cppkafka/build/include")
link_directories("/usr/local/lib")


add_executable(${EXAMPLE_BINARY} src/main.cpp 
                                src/config/config.cpp
                                src/config/Observer/Observer.cpp)


target_include_directories(${EXAMPLE_BINARY} PRIVATE "${CMAKE_BINARY_DIR}")
target_compile_options(${EXAMPLE_BINARY} PRIVATE -Wall -Wextra -pedantic -Werror )



target_link_libraries(${EXAMPLE_BINARY} PRIVATE 
                             ${CMAKE_THREAD_LIBS_INIT} 
                             ${Poco_LIBRARIES}
                             "PocoData"
                             "PocoDataMySQL"
                             "mysqlclient"
                             CppKafka::cppkafka
                             ${Boost_LIBRARIES}
                             ZLIB::ZLIB)


set_target_properties(${EXAMPLE_BINARY} PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(${EXAMPLE_BINARY} PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)



install(TARGETS ${EXAMPLE_BINARY} RUNTIME DESTINATION bin)