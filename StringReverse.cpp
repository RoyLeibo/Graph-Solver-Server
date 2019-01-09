
#include "StringReverse.h"
#include <string>
string StringReverse::solve(string problem)
{
    std:: string first_problem = problem;
    if(this->fileCacheManager->find_solution(problem))
    {
        return this->fileCacheManager->get_solution(problem);
    }
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
    std::pair<std::string,std::string> solution = make_pair(first_problem,problem);
    this->fileCacheManager->add_solution(solution);
    problem += "\r\n" ;
    return problem;
}

