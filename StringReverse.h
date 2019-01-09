
#ifndef FINAL_PROJECT_SECOND_StringReverse_H
#define FINAL_PROJECT_SECOND_StringReverse_H

#include <string>
#include <iostream>
#include "Solver.h"
#include "FileCacheManager.h"

using namespace std;

class StringReverse: public Solver <string,string> {
    private:
        FileCacheManager *fileCacheManager;
    public:
        string solve(string problem);

};


#endif //FINAL_PROJECT_SECOND_StringReverse_H
