#include "Server/SyncServer/CSyncServer.h"

#include <iostream>
#include <thread>

SyncServer::CSyncServer::CSyncServer( std::shared_ptr<boost::asio::ip::tcp::socket>& socket ) : 
mSocket(socket) {

}

SyncServer::CSyncServer::~CSyncServer() {

}

void SyncServer::CSyncServer::StartServer() {
        
}

void SyncServer::CSyncServer::StopServer() {

}

void SyncServer::CSyncServer::ThreadRunnable() {

}