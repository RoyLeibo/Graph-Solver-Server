//
// Created by royl8 on 1/9/19.
//

#ifndef FINAL_PROJECT_SECOND_MYCLIENTHANDLER_H
#define FINAL_PROJECT_SECOND_MYCLIENTHANDLER_H


#include <string>
#include <iostream>
#include "ClientHandler.h"

using namespace std ;

class MyClientHandler: public ClientHandler {

private:
    Solver<string, string>* solver ;

public:
    MyClientHandler(Solver<string, string>* string_solver) ;
    void handle_client(int sock_fd) ;
    bool is_end_line(char buffer[]) ;
    int size_of_matrix(string line) ;

    template <int rows, int columns>
    void matrix_build(int (&array)[rows][columns], string line, int size_of_matrix) ;

};


#endif //FINAL_PROJECT_SECOND_MYCLIENTHANDLER_H
