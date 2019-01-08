
#include "OpenThread.h"

void* run_solver(void* arg) {
  struct solver_struct* arg_struct_p = (solver_struct*)arg ;
  struct solver_struct arg_struct = *arg_struct_p;
  delete arg_struct_p;
  int sock_fd ;
  int* time_out_flag = 0 ;
  while(true) {
    sock_fd = OpenSocket().open_socket(arg_struct.port, time_out_flag) ;
    if(*time_out_flag == 0) {
        arg_struct.c_h.handle_client(sock_fd) ;
        close(sock_fd) ;
    }
    else {
        close(sock_fd) ;
        break ;
    }
  }
  pthread_exit(0) ;
}

void OpenThread::open_thread(int port, ClientHandler c_h) {

    // after connection has established, initialize a thread for reading data from the simulator
    pthread_t tid ;

    // initialize struct
    struct solver_struct* s_s = new solver_struct;
    s_s->port = port ;
    s_s->c_h = c_h ;  
  
    // create a thread with the struct and a function which reads data from the simulator,
    // parse it and update the variables map

    pthread_create(&tid, nullptr, run_solver, s_s) ;
}
