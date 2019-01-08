
#ifndef FINAL_PROJECT_SECOND_SERVER_H
#define FINAL_PROJECT_SECOND_SERVER_H

#include "ClientHandler.h"
namespace server_side {

    class Server {
        private:

        public:
            virtual void open(int port, ClientHandler ClientHandler);
            virtual void stop();
            virtual void start();
    };
}

#endif //FINAL_PROJECT_SECOND_SERVER_H
