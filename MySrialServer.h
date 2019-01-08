
#ifndef FINAL_PROJECT_SECOND_MYSRIALSERVER_H
#define FINAL_PROJECT_SECOND_MYSRIALSERVER_H

#include "Server.h"
#include "OpenThread.h"

class MySrialServer : public server_side::Server {
    private:
        OpenThread *openThread;
        ClientHandler* client_handler ;

    public:
        MySrialServer();
        virtual void open(int port, ClientHandler* client_handler);
        virtual void stop();
        virtual void start();
};


#endif //FINAL_PROJECT_SECOND_MYSRIALSERVER_H
