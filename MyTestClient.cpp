//
// Created by einat on 1/6/19.
//

#include "MyTestClient.h"

MyTestClient::MyTestClient() {
  this->solve = new Solver() ;
  this->socket_opener = new OpenSocket() ; 
}

void MyTestClient::handle_client(int sock_fd) {
  char buffer [256] ;
  bzero(buffer,256) ;
  while (true) {
    int n = read(sock_fd, buffer, 255) ;
    if (n < 0) { // if read is fail, print error
        perror("ERROR reading from socket");
    }
    else {
      if (!is_buffer_is_end()) {
        string problem = buffer ;
        return this->solve.solver(problem) ;
      }
      else {
        break ;
      }  
    }
  }
}  


bool MyTestClient if_buffer_is_end(char[] buffer) {
  if ((buffer[0] != 'e') || (buffer[1] != 'n') || (buffer[2] = 'd')) {
    return false ;
  }
  return true ;
}
