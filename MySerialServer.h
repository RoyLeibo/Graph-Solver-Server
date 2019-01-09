
#ifndef FINAL_PROJECT_SECOND_MYSRIALSERVER_H
#define FINAL_PROJECT_SECOND_MYSRIALSERVER_H

#include "Server.h"

class MySerialServer : public server_side::Server {
    private:
        OpenThread *openThread;
        ClientHandler* client_handler ;

    public:
        MySerialServer();
        virtual void open(int port, ClientHandler* client_handler);
        virtual void stop();
        virtual void start();
        ~MySerialServer();
};


#endif //FINAL_PROJECT_SECOND_MYSRIALSERVER_H
