
#include "StringReverse.h"

string StringReverse::solve(string problem)
{
    char reverse;
    int counter_from_end = problem.length() -1;
    for(int i = 0; i < problem.length() / 2; i++)
    {
        reverse = problem[counter_from_end];
        problem[counter_from_end] = problem[i];
        problem[i] = reverse;
        counter_from_end--;
    }
    problem.erase(0,2) ;
    problem += "\r\n" ;
    return problem;
}