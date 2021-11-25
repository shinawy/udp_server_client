#include "udpserversocket.h"

// UDPServerSocket:: UDPServerSocket (){

// }

bool UDPServerSocket:: initializeServer (char * _myAddr, int _myPort){
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket Creation Failed");
        return false;
    }
                                                                      
    myAddr.sin_family    = AF_INET;
    myAddr.sin_addr.s_addr = INADDR_ANY;
    myAddr.sin_port = htons(_myPort);

    if (bind(sock, (const struct sockaddr *)&_myAddr, sizeof(_myAddr)) < 0) {
        perror("Bind Failed");
        return false;
    } else {
        perror("Bind Done");
        return true;
    }
}

UDPServerSocket:: ~UDPServerSocket (){

}
