
#ifndef FINAL_PROJECT_SECOND_OPENSOCKET_H
#define FINAL_PROJECT_SECOND_OPENSOCKET_H

#include <iostream>

/* This class open a socket using a given port.
 * If there was a timeout during the wait for a client,
 * the class changes the time out flag
 */

class OpenSocket {

    public:
        int open_socket(int port, int* time_out_flag) ;

};


#endif //FINAL_PROJECT_SECOND_OPENSOCKET_H
