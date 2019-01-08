
#include "MyTestClient.h"

MyTestClient::MyTestClient() {
  this->solver = new Solver<class problem,class solution>() ;
}

void MyTestClient::handle_client(int sock_fd) {
  char buffer [256] ;
  string problem = "" ;
  string temp_buffer ;
  while (true) {
    memset(buffer, 0, 256) ;
    int n = read(sock_fd, buffer, 255) ;
    temp_buffer = buffer ;
    if (!is_end_line(buffer)) {
      problem += temp_buffer ;
      continue ;
    }
    problem += temp_buffer ;
    if (n < 0) { // if read is fail, print error
        perror("ERROR reading from socket");
    }
    else {
      if (!is_buffer_is_end(buffer)) {
        n = write(sockfd ,this->solver.solve(problem),18);
        problem = "" ;
        if (n < 0) {
          perror("ERROR writing to socket");
          exit(1);
        }
      }
      else {
        break ;
      }  
    }
  }
}  


bool MyTestClient::is_buffer_is_end(char buffer[]) {
  if ((buffer[0] != 'e') || (buffer[1] != 'n') || (buffer[2] = 'd')) {
    return false ;
  }
  return true ;
}

bool MyTestClient::is_end_line(char buffer[]) {
  string temp_buffer = buffer ;
  int is_end = temp_buffer.find('\n', 0) ;
  if (is_end == -1) {
    return false ;
  }
  return true ;
}
