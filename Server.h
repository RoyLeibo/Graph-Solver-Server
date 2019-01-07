//
// Created by einat on 1/6/19.
//

#ifndef FINAL_PROJECT_SECOND_SERVER_H
#define FINAL_PROJECT_SECOND_SERVER_H

namespace server_side {

    class Server {
        private:

        public:
            virtual void open();
            virtual void stop();
            virtual void start();
    };
}

#endif //FINAL_PROJECT_SECOND_SERVER_H
