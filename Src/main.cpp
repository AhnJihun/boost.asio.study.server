#include <iostream>
#include <string>

int main ( int argc , char** argv ) {

    for ( int i = 1 ; i  < argc ; i++ ) {
        std::cout << argv[i] << std::endl;
    }

    std::string portNumber(argv[2]);

    return 0;
}