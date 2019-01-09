
#ifndef FINAL_PROJECT_SECOND_SERVER_H
#define FINAL_PROJECT_SECOND_SERVER_H

#include <pthread.h>
#include "ClientHandler.h"
#include "OpenThread.h"

namespace server_side {

    class Server {

        public:
            virtual void open(int port, ClientHandler* client_handler) = 0;
            virtual void stop() = 0;
            virtual void start() = 0;
    };
}

#endif //FINAL_PROJECT_SECOND_SERVER_H
