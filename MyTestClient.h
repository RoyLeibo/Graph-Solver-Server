//
// Created by einat on 1/6/19.
//

#ifndef FINAL_PROJECT_SECOND_MYTESTCLIENT_H
#define FINAL_PROJECT_SECOND_MYTESTCLIENT_H

#include "ChlientHandler.h"

class MyTestClient : public ChlientHandler {
  
  Solver solve ;
  OpenSocket socket_opener ;
  
  public:
  MyTestClient() ;
  void handle_client(int sock_fd) ;

};


#endif //FINAL_PROJECT_SECOND_MYTESTCLIENT_H
