#include "client.h"
#define MAXLINE 1024

Client:: Client(char * _hostname, int _port){
udpClientSocket= new UDPClientSocket();
udpClientSocket ->initializeClient(_hostname, _port);
}

void Client::send_request(char* message){
int n;
socklen_t len; 
       char* buffer [MAXLINE];
    sendto(udpClientSocket -> sock, (const char *)message, strlen(message),
        MSG_CONFIRM, (const struct sockaddr *) &udpClientSocket->myAddr, 
            sizeof(udpClientSocket->myAddr));
    // printf("Hello message sent.\n");
           
    n = recvfrom(udpClientSocket -> sock, (char *)buffer, MAXLINE, 
                MSG_WAITALL, (struct sockaddr *) &udpClientSocket->myAddr,
               &len);
    buffer[n] = "\0";
    printf("Server : %s\n", buffer);
}

Message * Client:: execute(Message * _message){

}

Client:: ~Client(){
delete udpClientSocket;
}
