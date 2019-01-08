
#ifndef FINAL_PROJECT_SECOND_MYTESTCLIENT_H
#define FINAL_PROJECT_SECOND_MYTESTCLIENT_H

#include "ClientHandler.h"


class MyTestClient : public ClientHandler {

  private:
        Solver<class problem,class solution>* solver ;
  
  public:
        MyTestClient() ;
        void handle_client(int sock_fd) ;
        bool is_buffer_is_end(char buffer[]) ;
        bool is_end_line(char buffer[]) ;

};


#endif //FINAL_PROJECT_SECOND_MYTESTCLIENT_H
