
#include "MySerialServer.h"

MySerialServer::MySerialServer()
{
    this->openThread = new OpenThread();
}

void MySerialServer::open(int port, ClientHandler* client_handler)
{
    this->client_handler = client_handler ;
    this->openThread->open_thread(port, this->client_handler);
}

void MySerialServer::stop() {

}
void MySerialServer::start() {

}