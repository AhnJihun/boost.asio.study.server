#include "Server/SyncServer/CSyncAcceptor.h"

SyncServer::CSyncAcceptor::CSyncAcceptor (  const std::string& serverIp , 
                                            unsigned short portNum ) : 
mServerIp(serverIp) ,
mPortNum(portNum) ,
mIsRun(false) ,
mAcceptThread (nullptr) {

    boost::asio::io_service ioService;
    boost::asio::ip::tcp::endpoint endPoint(    boost::asio::ip::tcp::v4() ,
                                                mPortNum );

    mAcceptor = std::make_shared< boost::asio::ip::tcp::acceptor >( ioService , endPoint );
}

SyncServer::CSyncAcceptor::~CSyncAcceptor() {

}

bool SyncServer::CSyncAcceptor::StartAcceptor() {
    mIsRun = true;
    
    if ( nullptr == mAcceptThread ) { 
        mAcceptThread = std::make_shared<std::thread> ( 
            [&](){
                AcceptRunnable();
            }
        );
    }

    return true;
}

bool SyncServer::CSyncAcceptor::StopAcceptor() {
    mIsRun = false;


    
    return true;
}

void SyncServer::CSyncAcceptor::AcceptRunnable() {

    while ( true == mIsRun ) {
            
    }

    return;
}