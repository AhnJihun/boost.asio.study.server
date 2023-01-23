#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/asio.hpp>

#include "Server/SyncServer/CSyncServer.h"
#include "Server/SyncServer/CSyncAcceptor.h"

int main ( int argc , char** argv ) {

    for ( int i = 1 ; i  < argc ; i++ ) {
        std::cout << argv[i] << std::endl;
    }
    
    boost::asio::io_service ioService;

    SyncServer::CSyncAcceptor syncAcceptor( argv[1] ,
                                            &ioService ,
                                            boost::lexical_cast<unsigned short>(argv[2]) );

    syncAcceptor.StartAcceptor();
    
    return 0;
}