
#ifndef FINAL_PROJECT_SECOND_MYTESTCLIENT_H
#define FINAL_PROJECT_SECOND_MYTESTCLIENT_H

#include "ClientHandler.h"

class MyTestClient : public ClientHandler {
  
  Solver solver ;
  OpenSocket socket_opener ;
  
  public:
  MyTestClient() ;
  void handle_client(int sock_fd) ;

};


#endif //FINAL_PROJECT_SECOND_MYTESTCLIENT_H
