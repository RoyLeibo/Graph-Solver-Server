//
// Created by einat on 1/6/19.
//

#ifndef FINAL_PROJECT_SECOND_MYPARALLELSERVER_H
#define FINAL_PROJECT_SECOND_MYPARALLELSERVER_H

#include "Server.h"

class MyParallelServer : public server_side::Server {

    public:
        virtual void open();
        virtual void stop();
        virtual void start();
};


#endif //FINAL_PROJECT_SECOND_MYPARALLELSERVER_H
