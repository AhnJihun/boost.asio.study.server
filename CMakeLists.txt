cmake_minimum_required(VERSION 3.23)

project(
    boost.asio.study.server
)

set( SOURCE_DIR Src )
set( SOURCE_FILES ${SOURCE_DIR}/main.cpp )

message("Boost Path : $ENV{BOOST_PATH}")

set( BOOST_PATH $ENV{BOOST_PATH} )

#boost include & linking
include_directories(${BOOST_PATH}/include)
link_directories(${BOOST_PATH}/lib)

add_executable( boost.asio.study.clinet ${SOURCE_FILES} )