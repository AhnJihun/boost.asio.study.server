#include "Server/SyncServer/CSyncAcceptor.h"

SyncServer::CSyncAcceptor::CSyncAcceptor (  const std::string& serverIp , 
                                            boost::asio::io_service* ioService,
                                            unsigned short portNum ) : 
mServerIp(serverIp) ,
mPortNum(portNum) ,
mIsRun(false) ,
mAcceptThread (nullptr) ,
mIoService(ioService) {

    boost::asio::ip::tcp::endpoint endPoint(    boost::asio::ip::tcp::v4() ,
                                                mPortNum );

    mAcceptor = std::make_shared< boost::asio::ip::tcp::acceptor >( *ioService , endPoint );
}

SyncServer::CSyncAcceptor::~CSyncAcceptor() {
    if ( true == mAcceptThread->joinable() ) {
        mAcceptThread->join();
    }
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

    if ( true == mAcceptThread->joinable() ) {
        mAcceptThread->join();
    }

    return true;
}

bool SyncServer::CSyncAcceptor::StopAcceptor() {
    mIsRun = false;

    if ( true == mAcceptThread->joinable() ) {
        mAcceptThread->join();
    }
    
    return true;
}

void SyncServer::CSyncAcceptor::AcceptRunnable() {
    while ( true == mIsRun ) {
        //blocking aceept
        std::shared_ptr< boost::asio::ip::tcp::socket > waitConnectSocket = std::make_shared< boost::asio::ip::tcp::socket > ( *mIoService );
        mAcceptor->accept(*waitConnectSocket);
        //accept completed
        

    }

    return;
}