//
// Created by einat on 1/6/19.
//

#include "OpenThread.h"

void* run_solver(void* arg) {
  struct solver_struct* arg_struct_p = (solver_struct*)arg ;
  struct solver_struct arg_struct = *arg_struct_p;
  delete arg_struct_p;
  
  
  
  pthread_exit(0) ;
  
}

void OpenThread::open_thread(int port) {

    // after connection has established, initialize a thread for reading data from the simulator
    pthread_t tid ;

    // initialize struct
    struct solver_struct* s_s = new solver_struct;
    s_s->port = port ;
    
    // create a thread with the struct and a function which reads data from the simulator,
    // parse it and update the variables map
    pthread_create(&tid, nullptr, run_solver, r_s) ;
}
