This Readme is very important for compiling this project: 

Team Members: 
    Seef Kosbar         900183864
    Mahmoud A Elshinawy 900183926

Project Description: 
    The project is about server-client interaction. The program marshals the message and send it 
    to the server encrypted. In the server, the server unmarshals and decrypts the message taken from
    the client. For the sake of encryption test, we disabled the decryption function. 

Prerequisite: 
1. install the boost-c++ library:
    sudo apt-get install libboost-all-dev

Compiling: 

to compile, you need to use make as the compiling command requires linking boost libraries
to make different files use the command: 

server: 
    make -f Makefileserver
    make -f Makefileclient


