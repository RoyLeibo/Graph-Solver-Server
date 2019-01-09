
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
#include <vector>
#include <pthread.h>
#include "ClientHandler.h"

enum which_server_communication{SerialServer, ParallelServer};


void* run_solver_serial(void* arg) ;
void* run_solver_parallel(void* arg) ;
void* run_in_parallel(void* arg) ;

class OpenThread {

  public:
    pthread_t open_thread(int port, ClientHandler* c_h, int server_client_handle) ;
  
};

struct solver_struct {
    int port ;
    ClientHandler* c_h ;

};

struct parallel_struct {
    ClientHandler* c_h ;
    vector<pthread_t>* threads_id ;
    int port ;
    int sock_fd ;

};


#endif //FINAL_PROJECT_SECOND_OpenThread_H
