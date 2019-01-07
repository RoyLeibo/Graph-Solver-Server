//
// Created by einat on 1/6/19.
//

#ifndef FINAL_PROJECT_SECOND_MYSRIALSERVER_H
#define FINAL_PROJECT_SECOND_MYSRIALSERVER_H

#include "Server.h"
#include "OpenThtead.h"

class MySrialServer : public server_side::Server {
    private:
        OpenThread *openThread;
    public:
        MySrialServer
        virtual void open(int port, ChlientHandler chlientHandler);
        virtual void stop();
        virtual void start();
};


#endif //FINAL_PROJECT_SECOND_MYSRIALSERVER_H
