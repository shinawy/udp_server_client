#include "udpclientsocket.h"

// UDPClientSocket:: UDPClientSocket (){

// }

bool UDPClientSocket:: initializeClient (char * _peerAddr, int
_peerPort){

// Filling server information
    myAddr.sin_family = AF_INET;
    myAddr.sin_port = htons(_peerPort);
    myAddr.sin_addr.s_addr = INADDR_ANY;


}

UDPClientSocket:: ~UDPClientSocket ( ){

}
