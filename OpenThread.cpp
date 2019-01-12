
#include "OpenThread.h"

/* This function is used to run in serial server and solve a problem
 * received from client.
 */

void* run_solver_serial(void* arg) {
  struct solver_struct* arg_struct_p = (solver_struct*)arg ;
  struct solver_struct arg_struct = *arg_struct_p;
  delete arg_struct_p;
  int sock_fd ;
  int time_out_flag = 0 ;
  while(true) {
    // activate a function that open a socket using a specific port
    sock_fd = OpenSocket().open_socket(arg_struct.port, &time_out_flag) ;
    if(time_out_flag == 0) { // if there was no timeout
        // activate function which communicate with the client using the sock id which opened
        arg_struct.c_h->handle_client(sock_fd) ;
        close(sock_fd) ;
    }
    else {
        close(sock_fd) ; // if there was a timeout, end communication
        break ;
    }
  }
  pthread_exit(0) ;
}

/* This function is used to manage a parallel server which solve multiple problem * receives from
 * multiple client simultaneously.
 * For each client, a new thread is opened.
 */

void* run_solver_parallel(void* arg) {
    struct solver_struct* arg_struct_p = (solver_struct*)arg ;
    struct solver_struct arg_struct = *arg_struct_p;
    delete arg_struct_p;
    vector<pthread_t> threads_id ; // initialize a vector for all the thread's ids
    int sock_fd ;
    int time_out_flag = 0 ;
    while(true) {
        // activate a function that open a socket using a specific port
        sock_fd = OpenSocket().open_socket(arg_struct.port, &time_out_flag) ;
        if(time_out_flag == 0) { // if there was no timeout
            pthread_t tid; // initialize a new thread id
            parallel_struct* p_s = new parallel_struct ; // initialize a new struct to run in parallel
            ClientHandler* c_h_copy = arg_struct.c_h ; // initialize a client handler
            p_s->c_h = c_h_copy ; // insert the copy into struct
            p_s->threads_id_vec = &threads_id ; // insert the vector into struct
            p_s->sock_fd = sock_fd; // insert the sock id into struct
            p_s->this_thread_id = tid ; // insert this thread id into struct
            threads_id.push_back(tid); // push this thread's id into the vec
            // creates a new thread to run in parallel using the struct that has just initialize and the
            // run_in_parallel thread function.
            // When the thread is finished, it will delete it's id from the vector.
            pthread_create(&tid, nullptr, run_in_parallel, p_s);
        }
        else {
            // When there was a time out, the program will not receive any more clients.
            // The loop will run throw the threads_id vector and using the function "pthread_join"
            // function to "wait" until all threads is finished handling it's clients.
            int threads_id_size = threads_id.size() ;
            for(int i = 0 ; i < threads_id_size ; i++) {
                // activate join function for ever thread left in the vec
                pthread_join(threads_id.at(i), NULL) ;
            }
            break ;
        }
    }
    pthread_exit(0) ;
}

/* This function is activated from the run_parallel_server function.
 * The function is run in a different thread and communicate with a client.
 */

void* run_in_parallel(void* arg) {
    struct parallel_struct* arg_struct_p = (parallel_struct*)arg ;
    struct parallel_struct arg_struct = *arg_struct_p;
    delete arg_struct_p ;
    arg_struct.c_h->handle_client(arg_struct.sock_fd) ;
    close(arg_struct.sock_fd) ;
    int threads_id_size = arg_struct.threads_id_vec->size() ;
    for(int i = 0 ; i < threads_id_size ; i++) {
        if(arg_struct.threads_id_vec->at(i) == arg_struct.this_thread_id ) {
            arg_struct.threads_id_vec->erase(arg_struct.threads_id_vec->begin() + i) ;
            break ;
        }
    }
    pthread_exit(0) ;
}

// function that opens the first thread.

pthread_t OpenThread::open_thread(int port, ClientHandler* c_h, int server_client_handle) {

    // after connection has established, initialize a thread for reading data from the simulator
    pthread_t tid ;

    // initialize struct

    struct solver_struct* s_s = new solver_struct;
    s_s->port = port ;
    s_s->c_h = c_h ;  
  
    // The switch case is to indicate in which type of server to use: serial or parallel.
    // than, it creates a thread with the struct and a function which reads data from the simulator,
    // parse it and update the variables map

    switch(server_client_handle) {
        case(SerialServer): pthread_create(&tid, nullptr, run_solver_serial, s_s) ; return tid ;
        case(ParallelServer): pthread_create(&tid, nullptr, run_solver_parallel, s_s) ; return tid ;
    }
}
