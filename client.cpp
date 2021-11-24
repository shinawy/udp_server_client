#include "client.h"
#define MAXLINE 1024

Client:: Client(char * _hostname, int _port){
udpClientSocket ->initializeClient(_hostname, _port);
}

void Client::send_request(char* message){
int n, len;
       char* buffer [MAXLINE];
    sendto(udpClientSocket -> sock, (const char *)message, strlen(message),
        MSG_CONFIRM, (const struct sockaddr *) &udpClientSocket->myAddr, 
            sizeof(udpClientSocket->myAddr));
    printf("Hello message sent.\n");
           
    n = recvfrom(udpClientSocket -> sock, (char *)buffer, MAXLINE, 
                MSG_WAITALL, (struct sockaddr *) &udpClientSocket->myAddr,
                (socklen_t *)&len);
    buffer[n] = "\0";
    printf("Server : %s\n", buffer);
}

Message * Client:: execute(Message * _message){

}

Client:: ~Client(){

}
