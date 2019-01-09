//
// Created by royl8 on 1/9/19.
//

#ifndef FINAL_PROJECT_SECOND_MYCLIENTHANDLER_H
#define FINAL_PROJECT_SECOND_MYCLIENTHANDLER_H


#include <string>
#include <iostream>
#include <vector>
#include "ClientHandler.h"
#include "Matrix.h"

using namespace std ;

class MyClientHandler: public ClientHandler {

private:
    Solver<string, string>* solver ;

public:
    MyClientHandler(Solver<string, string>* string_solver) ;
    void handle_client(int sock_fd) ;
    bool is_end_line(char buffer[]) ;
    virtual ~MyClientHandler() ;

};


#endif //FINAL_PROJECT_SECOND_MYCLIENTHANDLER_H
