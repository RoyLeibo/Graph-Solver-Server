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
    int num_of_raws;
    while (true) {
        memset(buffer, 0, 256);
        int n = read(sock_fd, buffer, 256);
        if (n < 0) { // if read is fail, print error
            perror("ERROR reading from socket");
        }
        temp_buffer = buffer;
        if (!is_end_line(buffer)) {
            line += temp_buffer;
            continue;
        }
        line += temp_buffer;
        if (is_first_line) {
            num_of_raws = size_of_matrix(line);
            is_first_line = false;
        }
        if (line != "end\r\n") {
            temp_buffer = this->solver->solve(line);
            answer = &temp_buffer[0];
            n = write(sock_fd, answer, temp_buffer.length());
            line = "";
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
        } else {
            break;
        }
    }
}

bool MyClientHandler::is_end_line(char buffer[]) {
    string temp_buffer = buffer;
    int is_end = temp_buffer.find('\r\n', 0);
    if (is_end == -1) {
        return false;
    }
    return true;
}

int MyClientHandler::size_of_matrix(string line) {
    int counter ;
    int end_of_line = line.find("\r\n", 0) ;
    int start_of_num = 0 ;
    int end_of_num ;
    while(start_of_num >= line.length()) {
        end_of_num = line.find(",", start_of_num) ;
        counter++ ;
        start_of_num = end_of_num + 1 ;
    }
    return counter ;
}

template <int rows, int columns>
void MyClientHandler::line_parser(int (&array)[rows][columns], string line, int size_of_matrix) {

}

