
#ifndef FINAL_PROJECT_SECOND_OpenThread_H
#define FINAL_PROJECT_SECOND_OpenThread_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include "ClientHandler.h"


void* run_solver(void* arg) ;

class OpenThread {

  public:
        void open_thread(int port, ClientHandler c_h) ;
  
};

struct solver_struct {
    int port ;
    ClientHandler c_h ;

};


#endif //FINAL_PROJECT_SECOND_OpenThread_H
