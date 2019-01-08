
#include "MySrialServer.h"

MySrialServer::MySrialServer()
{
    this->openThread = new OpenThread();
}

void MySrialServer::open(int port, ClientHandler* client_handler)
{
    this->client_handler = client_handler ;
    this->openThread->open_thread(port, this->client_handler);
}

void MySrialServer::stop() {

}
void MySrialServer::start() {

}