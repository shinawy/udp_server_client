#include "server.h"
#define MAXLINE 4096

Server::Server(char * _listen_hostname, int _listen_port){
   udpServerSocket = new UDPServerSocket();

    bool x  = udpServerSocket -> initializeServer(_listen_hostname, _listen_port);
    if (x) {
        printf("Server Intialized.\n");
    } else {
        printf("Error: Server Not Intialized.\n");
    }
}

Message * Server:: getRequest(){
int n;
socklen_t len;
    len = sizeof(udpServerSocket-> peerAddr);  //len is value/resuslt
    cout<<"len: "<<len<<endl;
   char buffer[MAXLINE];
   Message* client_message= new Message();
   char *message_buffer = new char[sizeof(*client_message)];
   
   
   n = recvfrom(udpServerSocket->sock,  (Message*)message_buffer, MAXLINE, 
                MSG_WAITALL, ( struct sockaddr *) &udpServerSocket->peerAddr,&len);
    client_message = (Message *)`;
    cout<<"received 5las"<<endl;
    cout<<"Size of the Message object : " <<  sizeof(*client_message)<<endl;

    // strcpy(buffer, client_message -> getMessage());
    //    buffer[n] = NULL;
    //    MessageType message_type= Request;0
    // Message* client_message= new Message(message_type,0, buffer, strlen(buffer),1);
    // char* body_message= (char*) client_message -> getMessage();
    printf("Client : %d\n", strlen((char*)client_message -> message));
    cout<<"Size of the Message object : " << client_message->getMessageSize()<<endl;

    return client_message;
}

Message * Server:: doOperation(){

}

void Server:: sendReply (Message * _message){

   char* hello_server= (char *)"This is the server\n";
   //_message -> marshal;
   socklen_t len;
    len = sizeof(udpServerSocket-> peerAddr);  //len is value/resuslt

sendto(udpServerSocket->sock, (const char *)hello_server, strlen(hello_server), 
        MSG_CONFIRM, (const struct sockaddr *) &udpServerSocket->peerAddr,
            len);
}



void Server::serveRequest(){
// int len, n;

   while(true){
       Message* client_message= getRequest();
       doOperation();
       sendReply(client_message);  
    
    // printf("Hello message sent.\n");
   }

}

Server::~Server(){
    delete udpServerSocket;

}
