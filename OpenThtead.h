//
// Created by einat on 1/6/19.
//

#ifndef FINAL_PROJECT_SECOND_OPENTHTEAD_H
#define FINAL_PROJECT_SECOND_OPENTHTEAD_H

void* run_solver(void* arg) ;

class OpenThread {

  public:
  void open_thread(int port, ChlientHandler c_h) ;
  
};

struct solver_struct {
    int port ;
    ChlientHandler c_h ;

};


#endif //FINAL_PROJECT_SECOND_OPENTHTEAD_H
