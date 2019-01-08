
#include "MySrialServer.h"
MySrialServer::MySrialServer()
{
    this->openThread =   new  OpenThread();
}

void MySrialServer:: open(int port, ClientHandler ClientHandler)
{
    this->openThread->open_thread(port);
}