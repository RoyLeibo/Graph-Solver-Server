//
// Created by royl8 on 1/9/19.
//

#include "MyClientHandler.h"

MyClientHandler::MyClientHandler(Solver<string, string> *string_solver) {
    this->solver = string_solver;
}

void MyClientHandler::handle_client(int sock_fd) {
    char buffer[256];
    char *answer;
    string line = "";
    string temp_buffer;
    bool is_first_line = true;
    vector<string> matrix_vec;
    while (true) {
        memset(buffer, 0, 256) ;
        int n = read(sock_fd, buffer, 256);
        if (n < 0) { // if read is fail, print error
            perror("ERROR reading from socket");
        }
        temp_buffer = buffer ;
        if (!is_end_line(buffer)) {
            line += temp_buffer ;
            continue ;
        }
        line += temp_buffer;
        if (line != "end\r\n") {
            matrix_vec.push_back(line);
        } else {
//          temp_buffer = this->solver->solve(Matrix(matrix_vec)) ;
temp_buffer = "aaa" ;
            answer = &temp_buffer[0];
            n = write(sock_fd, answer, temp_buffer.length());
            line = "" ;
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
            break;
        }
    }
}

bool MyClientHandler::is_end_line(char buffer[]) {
    string temp_buffer = buffer;
    int is_end = temp_buffer.find("\r\n", 0);
    if (is_end == -1) {
        return false;
    }
    return true;
}
MyClientHandler::~MyClientHandler()
{
    delete(this->solver);
}
