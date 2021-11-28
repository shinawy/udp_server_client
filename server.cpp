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
   Message client_message;
   char *message_buffer = new char[sizeof(client_message)];
   

   stringstream servstream; 
   n = recvfrom(udpServerSocket->sock,  (char*) message_buffer, MAXLINE, 
                MSG_WAITALL, ( struct sockaddr *) &udpServerSocket->peerAddr,&len);
    
    cout<<"received"<<endl; 
    servstream= (stringstream) message_buffer;

    // Message client_message;
    {
        boost::archive::text_iarchive ia(servstream);
        ia >> client_message;
    }
    cout<<"message_buffer in the server: "<< message_buffer<<endl; 
    cout<<"the stream in the server contains: "<< servstream.str()<<endl; 


    // n = recvfrom(udpServerSocket->sock,  (Message*)& client_message, MAXLINE, 
    //             MSG_WAITALL, ( struct sockaddr *) &udpServerSocket->peerAddr,&len);


    // client_message = (Message*)&message_buffer; 
    ofstream outobj("server_obj.txt");
    outobj.write((char*)&client_message, sizeof(client_message));
    outobj.close();
    cout<<"received 5las"<<endl;
    cout<<"size: "<<sizeof(client_message)<<endl;

    client_message.print_message_info();
    // cout<<"Size of the Message object : " <<  sizeof(*client_message)<<endl;

    // strcpy(buffer, client_message -> getMessage());
    //    buffer[n] = NULL;
    //    MessageType message_type= Request;0
    // Message* client_message= new Message(message_type,0, buffer, strlen(buffer),1);
    
    // char* body_message= (char*) client_message -> getMessage();

    // char vmsg [client_message -> getMessageSize()]= client_message -> getMessage();
    // printf("vmsg: %s\n", client_message -> getMessage());
    // (uint8_t*) buni = (uint8_t*) vmsg;
    // int j;
    // for(j = 0; j < client_message->getMessageSize(); ++j)
    // printf("%02x\n", ((uint8_t*) vmsg)[j]);

// char* cmsg = (char*)calloc(sizeof(char), client_message->getMessageSize() + 1);

// char* msg = static_cast<char*>( calloc(sizeof(char), client_message->getMessageSize() + 1) );

// char* msg;
// msg = client_message.getMessage();
// msg= "manup";
// printf("sizeof message new: %d\n", strlen(msg)); 


// printf("client:::new::: %s\n", msg);
// msg= (char*) vmsg; 
//     char * cmsg= vmsg;

// msg = vmsg;
//     cout<< "Client:::: "<<msg<<endl;
    // printf("Client : %s\n", (char*) vmsg);


    // cout<<"Client::::::"<< client_message -> getMessage()<<endl;
    cout<<"Size of the Message : " << client_message.getMessageSize()<<endl;

    return &client_message;
}

Message * Server:: doOperation(){

}

void Server:: sendReply (Message * _message){

   string comm; 
   getline(cin,comm);
    MessageType message_type= Reply;
    Message server_message(message_type,0, (char*)comm.c_str(), comm.length()+1,1);

    char* marshaled_message= server_message.marshal();
    server_message.setMessage(marshaled_message,strlen(marshaled_message));
    cout<<"Message to be sent: \n";
    server_message.print_message_info();
    stringstream histream;
{
        boost::archive::text_oarchive oa(histream);
        oa << server_message;
    } // <-- destructor of text_oarchive


    // string hi= "helllo from the other side\n";
   
    // histream<<hi;
    histream.seekg(0, ios::end);
    int size = histream.tellg();

   //_message -> marshal;
   socklen_t len;
    len = sizeof(udpServerSocket-> peerAddr);  //len is value/resuslt

sendto(udpServerSocket->sock, histream.str().c_str(), size, 
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
