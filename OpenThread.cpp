
#include "OpenThread.h"

void* run_solver_serial(void* arg) {
  struct solver_struct* arg_struct_p = (solver_struct*)arg ;
  struct solver_struct arg_struct = *arg_struct_p;
  delete arg_struct_p;
  int sock_fd ;
  int time_out_flag = 0 ;
  while(true) {
    sock_fd = OpenSocket().open_socket(arg_struct.port, &time_out_flag) ;
    if(time_out_flag == 0) {
        arg_struct.c_h->handle_client(sock_fd) ;
        close(sock_fd) ;
    }
    else {
        close(sock_fd) ;
        break ;
    }
  }
  pthread_exit(0) ;
}

void* run_solver_parallel(void* arg) {
    struct solver_struct* arg_struct_p = (solver_struct*)arg ;
    struct solver_struct arg_struct = *arg_struct_p;
    delete arg_struct_p;
    vector<pthread_t> threads_id ;
    int sock_fd ;
    int time_out_flag = 0 ;
    while(true) {
        sock_fd = OpenSocket().open_socket(arg_struct.port, &time_out_flag) ;
        if(time_out_flag == 0) {
            pthread_t tid;
            parallel_struct* p_s = new parallel_struct ;
            ClientHandler* c_h_copy = arg_struct.c_h ;
            p_s->c_h = c_h_copy ;
            p_s->threads_id = &threads_id ;
            p_s->sock_fd = sock_fd;
            p_s->this_id = tid ;
            threads_id.push_back(tid);
            pthread_create(&tid, nullptr, run_in_parallel, p_s);
        }
        else {
            int threads_id_size = threads_id.size() ;
            for(int i = 0 ; i < threads_id_size ; i++) {
                pthread_join(threads_id.at(i), NULL) ;
            }
            break ;
        }
    }
    pthread_exit(0) ;
}

void* run_in_parallel(void* arg) {
    struct parallel_struct* arg_struct_p = (parallel_struct*)arg ;
    struct parallel_struct arg_struct = *arg_struct_p;
    delete arg_struct_p ;
    arg_struct.c_h->handle_client(arg_struct.sock_fd) ;
    close(arg_struct.sock_fd) ;
    int threads_id_size = arg_struct.threads_id->size() ;
    for(int i = 0 ; i < threads_id_size ; i++) {
        if(arg_struct.threads_id->at(i) == arg_struct.this_id) {
            arg_struct.threads_id->erase(arg_struct.threads_id->begin() + i) ;
            break ;
        }
    }
    pthread_exit(0) ;
}

pthread_t OpenThread::open_thread(int port, ClientHandler* c_h, int server_client_handle) {

    // after connection has established, initialize a thread for reading data from the simulator
    pthread_t tid ;

    // initialize struct
    struct solver_struct* s_s = new solver_struct;
    s_s->port = port ;
    s_s->c_h = c_h ;  
  
    // create a thread with the struct and a function which reads data from the simulator,
    // parse it and update the variables map

    switch(server_client_handle) {
        case(SerialServer): pthread_create(&tid, nullptr, run_solver_serial, s_s) ; return tid ;
        case(ParallelServer): pthread_create(&tid, nullptr, run_solver_parallel, s_s) ; return tid ;
    }
}
