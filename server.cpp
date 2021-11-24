#include "server.h"
#define MAXLINE 1024
Server::Server(char * _listen_hostname, int _listen_port){

udpServerSocket -> initializeServer(_listen_hostname, _listen_port);

}

void Server::serveRequest(){
int len, n;
   char* hello_server= "This is the server\n";
    len = sizeof(udpServerSocket-> peerAddr);  //len is value/resuslt
   char buffer[MAXLINE];
    n = recvfrom(udpServerSocket->sock, (char *)buffer, MAXLINE, 
                MSG_WAITALL, ( struct sockaddr *) &udpServerSocket->peerAddr,(socklen_t *) &len);

       buffer[n] = NULL;

    printf("Client : %s\n", buffer);
    sendto(udpServerSocket->sock, (const char *)hello_server, strlen(hello_server), 
        MSG_CONFIRM, (const struct sockaddr *) &udpServerSocket->peerAddr,
            len);
    printf("Hello message sent.\n");


}

Server::~Server(){

}
