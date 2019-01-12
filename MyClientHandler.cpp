//
// Created by royl8 on 1/9/19.
//

#include "MyClientHandler.h"

MyClientHandler::MyClientHandler(Solver<Searchable*, string> *searcher_solver) {
    this->searcher_solver = searcher_solver;
}

void MyClientHandler::handle_client(int sock_fd) {
    char buffer[256];
    char *answer;
    string line = "";
    string temp_buffer;
    vector<string> matrix_vec;
    while (true) {
        memset(buffer, 0, 256) ;
        int n = read(sock_fd, buffer, 256);
        if (n < 0) { // if read is fail, print error
            perror("ERROR reading from socket");
        }
        temp_buffer = buffer ;
        if (!is_end_line(&temp_buffer)) {
            line += temp_buffer ;
            continue ;
        }
        line += temp_buffer;
        if (line != "end") {
            matrix_vec.push_back(line);
            line = "" ;
        }
        else {
            Searchable* temp_matrix = new Matrix(matrix_vec) ;
            if(temp_matrix->get_n() > -1) {
                temp_buffer = this->searcher_solver->solve(temp_matrix);
                answer = &temp_buffer[0];
            }
            else {
                answer = "Matrix Is Illigal!" ;
            }
            n = write(sock_fd, answer, temp_buffer.length());
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
            break;
        }
    }
}

bool MyClientHandler::is_end_line(string* buffer) {
    int is_end = buffer->find("\r", 0);
    if (is_end == -1) {
        return false;
    }
    else {
        buffer->erase(is_end, 2) ;
        return true;
    }

}

MyClientHandler::~MyClientHandler()
{
    delete(this->searcher_solver);
}

bool MyClientHandler::input_check(vector<string> matrix_vec) {


}