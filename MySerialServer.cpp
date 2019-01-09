
#include "MySerialServer.h"

MySerialServer::MySerialServer()
{
    this->openThread = new OpenThread();
}

void MySerialServer::open(int port, ClientHandler* client_handler)
{
    this->client_handler = client_handler ;
    pthread_t thread_id =  this->openThread->open_thread(port, this->client_handler, 0);
    pthread_join(thread_id, NULL) ;
}

void MySerialServer::stop() {

}

void MySerialServer::start() {

}

MySerialServer::~MySerialServer()
{
    delete(this->openThread);
}