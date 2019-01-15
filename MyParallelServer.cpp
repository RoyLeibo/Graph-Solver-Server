
#include "MyParallelServer.h"

MyParallelServer::MyParallelServer()
{
    this->openThread = new OpenThread();
}

void MyParallelServer::open(int port, ClientHandler* client_handler)
{
    this->client_handler = client_handler ;
    pthread_t thread_id = this->openThread->open_thread(port, this->client_handler, 1);
    pthread_join(thread_id, nullptr) ;
}

void MyParallelServer::stop() {

}

void MyParallelServer::start() {

}

MyParallelServer::~MyParallelServer(){};
