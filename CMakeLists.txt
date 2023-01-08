cmake_minimum_required(VERSION 3.23)

project(
    boost.asio.study.server
)

set(CMAKE_CXX_STANDARD 17)

set( HEADER_DIR Inc )
set( SOURCE_DIR Src )

set( SOURCE_FILES   ${SOURCE_DIR}/main.cpp
                    ${SOURCE_DIR}/Server/SyncServer/CSyncServer.cpp
                    ${SOURCE_DIR}/Server/SyncServer/CSyncAcceptor.cpp )


message("Boost Path : $ENV{BOOST_PATH}")

set( BOOST_PATH $ENV{BOOST_PATH} )

#boost include & linking
include_directories(    ${BOOST_PATH}/include
                        ${HEADER_DIR}/ )

link_directories(${BOOST_PATH}/lib)

add_executable( boost.asio.study.clinet ${SOURCE_FILES} )