#ifndef FINAL_PROJECT_SECOND_MYPARALLELSERVER_H
#define FINAL_PROJECT_SECOND_MYPARALLELSERVER_H

#include "Server.h"

class MyParallelServer : public server_side::Server {

private:
    OpenThread *openThread;
    ClientHandler* client_handler ;

    public:
        MyParallelServer() ;
        void open(int port, ClientHandler* client_handler);
        void stop() ;
        void start() ;
        virtual ~MyParallelServer() ;
};


#endif //FINAL_PROJECT_SECOND_MYPARALLELSERVER_H
