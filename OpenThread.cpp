
#include "OpenThread.h"
#include "Main.h"

/* This function is used to run in serial server and solve a problem
 * received from client.
 */

void* run_solver_serial(void* arg) {
  struct solver_struct* arg_struct_p = (solver_struct*)arg ;
  struct solver_struct arg_struct = *arg_struct_p;
  delete arg_struct_p;
  int time_out_flag = 0 ;
  OpenSocket* open_socket ;
    int sock_fd = open_socket->open_socket(arg_struct.port) ;
    bool is_first_client = true ;
    int clilen ;
    struct sockaddr_in cli_addr ;
    listen(sock_fd, std::numeric_limits<int>::max()); // wait for a connection request
    clilen = sizeof(cli_addr);
    while(true) {
    // activate a function that open a socket using a specific port
    open_socket->listen_to_client(arg_struct.port, &time_out_flag, &is_first_client, clilen) ;
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
    ClientHandler* c_h = arg_struct.c_h ;
    int time_out_flag = 0 ;
    bool is_first_client = true ;
    OpenSocket* open_socket ;
    int sock_fd = open_socket->open_socket(arg_struct.port) ;
    int new_sock_fd, clilen ;
    struct sockaddr_in cli_addr ;
    listen(sock_fd, std::numeric_limits<int>::max()); // wait for a connection request
    clilen = sizeof(cli_addr);
    vector<bool*> all_threads_flags_vec;
    while(true) {
        new_sock_fd = open_socket->listen_to_client(sock_fd, &time_out_flag, &is_first_client, clilen) ;

        // activate a function that open a socket using a specific port

        if(time_out_flag == 0) { // if there was no timeout

            pthread_t tid ; // initialize a new thread id
            bool* is_thread_finished = new bool(false);
            all_threads_flags_vec.push_back(is_thread_finished) ;
            parallel_struct* p_s = new parallel_struct ; // initialize a new struct to run in parallel
            p_s->c_h = c_h ; // insert the copy into struct
            p_s->sock_fd = new_sock_fd ; // insert the sock id into struct
            p_s->is_thread_finished = is_thread_finished ; // insert this thread id into struct
            // creates a new thread to run in parallel using the struct that has just initialize and the
            // run_in_parallel thread function.
            // When the thread is finished, it will delete it's id from the ve
            pthread_create(&tid, nullptr, run_in_parallel, p_s);

        }
        else {
            // When there was a time out, the program will not receive any more clients.
            // The loop will run throw the threads_id vector and using the function "pthread_join"
            // function to "wait" until all threads is finished handling it's clients.
            int counter ;
            while (true) {
                counter = 0 ;
                cout << "vector size: " << all_threads_flags_vec.size() << endl ;
//                cout << "Thread " << 1 << " is " << *all_threads_flags_vec.at(0) << endl ;
//                cout << "Thread " << 2 << " is " << *all_threads_flags_vec.at(1) << endl ;
//                cout << "Thread " << 3 << " is " << *all_threads_flags_vec.at(2) << endl ;
//                cout << "Thread " << 4 << " is " << *all_threads_flags_vec.at(3) << endl ;
//                cout << "Thread " << 5 << " is " << *all_threads_flags_vec.at(4) << endl ;
//                cout << "Thread " << 6 << " is " << *all_threads_flags_vec.at(5) << endl ;
                for(int i = 0 ; i < all_threads_flags_vec.size() ; i++) {
                    if (*all_threads_flags_vec.at(i) == false) {
                        break ;
                    }
                    counter++ ;
                }
                cout << "number of thread still running now: " << all_threads_flags_vec.size()-counter << endl ;
                if (counter == all_threads_flags_vec.size()) {
                    cout << "all thread is finished" << endl ;
                    break ;
                }
                cout << "start loop again.." << endl ;
            }
            for(int i = 0 ; i < all_threads_flags_vec.size() ; i++) {
                delete(all_threads_flags_vec.at(i)) ;
            }
            break ;
        }
    }
//    delete(open_socket) ;
//    delete(c_h) ;
}

/* This function is activated from the run_parallel_server function.
 * The function is run in a different thread and communicate with a client.
 */

void* run_in_parallel(void* arg) {
    struct parallel_struct* arg_struct_p = (parallel_struct*)arg ;
    struct parallel_struct arg_struct = *arg_struct_p ;
    delete arg_struct_p ;
    arg_struct.c_h->handle_client(arg_struct.sock_fd) ;
    close(arg_struct.sock_fd) ;
    *arg_struct.is_thread_finished = true ;
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

OpenThread::~OpenThread(){};
