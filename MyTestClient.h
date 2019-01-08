
#ifndef FINAL_PROJECT_SECOND_MYTESTCLIENT_H
#define FINAL_PROJECT_SECOND_MYTESTCLIENT_H

#include "ClientHandler.h"

class MyTestClient : public ClientHandler {
  
  Solver solver ;
  OpenSocket socket_opener ;
  
  public:
  MyTestClient() ;
  void handle_client(int sock_fd, bool* end_flag) ;

};


#endif //FINAL_PROJECT_SECOND_MYTESTCLIENT_H
