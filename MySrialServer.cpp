//
// Created by einat on 1/6/19.
//

#include "MySrialServer.h"
MySrialServer::MySrialServer()
{
    this->openThread =   new  OpenThread();
}

void MySrialServer:: open(int port, ChlientHandler chlientHandler)
{
    this->openThread->open_thread(port);
}