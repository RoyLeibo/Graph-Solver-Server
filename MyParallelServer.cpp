
#include "MyParallelServer.h"

MyParallelServer::MyParallelServer(int port, ClientHandler* client_handler)
{
    this->openThread = new OpenThread();
}

void MyParallelServer::open(int port, ClientHandler* client_handler)
{
    this->client_handler = client_handler ;
    pthread_t thread_id = this->openThread->open_thread(port, this->client_handler, 1);
    pthread_join(thread_id, NULL) ;
}

void MyParallelServer::stop() {

}
void MyParallelServer::start() {

}