#include "Server/SyncServer/CSyncAcceptor.h"

SyncServer::CSyncAcceptor::CSyncAcceptor (  const std::string& serverIp , 
                                            unsigned short portNum ) : 
mServerIp(serverIp) ,
mPortNum(portNum) {

    boost::asio::io_service ioService;
    boost::asio::ip::tcp::endpoint endPoint(    boost::asio::ip::tcp::v4() ,
                                                mPortNum );

    mAcceptor = std::make_shared< boost::asio::ip::tcp::acceptor >( ioService , endPoint );
}

SyncServer::CSyncAcceptor::~CSyncAcceptor() {

}

bool SyncServer::CSyncAcceptor::StartAcceptor() {
    
}

bool SyncServer::CSyncAcceptor::StopAcceptor() {

}

void SyncServer::CSyncAcceptor::AcceptRunnable() {
    
}