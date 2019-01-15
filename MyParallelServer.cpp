
#include "MyParallelServer.h"
#include "Main.h"

MyParallelServer::MyParallelServer()
{
    this->openThread = new OpenThread();
}

void MyParallelServer::open(int port, ClientHandler* client_handler)
{
    this->client_handler = client_handler ;
    int sock_fd ;
    struct sockaddr_in serv_addr ;
    int enable=1;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0); // calling to socket function

    // Sets the socket to be reused

    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) != 0){
        perror("Cannot reuse address");
        exit(1);
    }

    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEPORT, &enable, sizeof(int)) != 0){
        perror("Cannot reuse port");
        exit(1);
    }

    if (sock_fd < 0) { // if the function failed, print error
        perror("cannot open socket, please try again");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr)); // initialize the socket struct

    // update socket's data

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);


    if (bind(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) { // binding host address
        perror("cannot bind to server");
        exit(1);
    }

    int new_sock_fd, clilen ;
    struct sockaddr_in cli_addr ;

    // sets timeout's definition
    timeval client_timeout ;
    client_timeout.tv_sec = 0;
    client_timeout.tv_usec = 0 ;
    timeval server_timeout ;
    server_timeout.tv_sec = 5;
    server_timeout.tv_usec = 0;

    listen(sock_fd, std::numeric_limits<int>::max()); // wait for a connection request
    clilen = sizeof(cli_addr);

    while(true) {
        // accept the connection request
        new_sock_fd = accept(sock_fd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
        if (new_sock_fd >= 0) {
            pthread_t tid ; // initialize a new thread id
            cout << "This thread's id is: " << tid << endl ;
            this->threads_id.push_back(tid); // push this thread's id into the vec

            parallel_struct* p_s = new parallel_struct ; // initialize a new struct to run in parallel
            p_s->c_h = this->client_handler ; // insert the copy into struct
            p_s->threads_id_vec = &this->threads_id ; // insert the vector into struct
            p_s->sock_fd = new_sock_fd ; // insert the sock id into struct
            p_s->this_thread_id = tid ; // insert this thread id into struct

            // creates a new thread to run in parallel using the struct that has just initialize and the
            // run_in_parallel thread function.
            // When the thread is finished, it will delete it's id from the ve
            pthread_create(&tid, nullptr, run_in_parallel, p_s);
        }
        else {
            if (errno == EWOULDBLOCK) {
                pthread_mutex_lock(&mutex3) ;
                // When there was a time out, the program will not receive any more clients.
                // The loop will run throw the threads_id vector and using the function "pthread_join"
                // function to "wait" until all threads is finished handling it's clients.
                cout << "The vector includes: " << endl ;
                for (int i = 0 ; i < this->threads_id.size(); i ++) {
                    cout << this->threads_id.at(i) << endl ;
                }

                for (int i = 0 ; i < this->threads_id.size() ; i++) {
                    cout << "inside join loop" << endl ;
                    pthread_join(this->threads_id.at(i), nullptr);
                    cout << "join to " << this->threads_id.at(i) << endl ;
                }
                pthread_mutex_unlock(&mutex3) ;
                break ;

            } else {
                perror("other error");
                exit(3);
            }
        }
        setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, (char *) &server_timeout, sizeof(server_timeout));
        setsockopt(new_sock_fd, SOL_SOCKET, SO_RCVTIMEO, (char *) &client_timeout, sizeof(client_timeout));
    }

//    pthread_t thread_id = this->openThread->open_thread(port, this->client_handler, 1);
//    pthread_join(thread_id, nullptr) ;
}

void MyParallelServer::stop() {

}

void MyParallelServer::start() {

}

MyParallelServer::~MyParallelServer(){};
