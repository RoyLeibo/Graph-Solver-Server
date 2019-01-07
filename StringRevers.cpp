//
// Created by einat on 1/7/19.
//

#include "StringRevers.h"

string StringRevers::solve(string problem)
{
    char revers;
    int counter_from_end = problem.length() -1;
    for(int i = 0; i < problem.length() / 2; i++)
    {
        revers = problem[counter_from_end];
        problem[counter_from_end] = problem[i];
        problem[i] = revers;
        counter_from_end--;
    }
    return problem;
}