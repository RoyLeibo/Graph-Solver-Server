
#ifndef FINAL_PROJECT_SECOND_OpenThread_H
#define FINAL_PROJECT_SECOND_OpenThread_H

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
