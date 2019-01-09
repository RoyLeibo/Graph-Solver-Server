
#ifndef FINAL_PROJECT_SECOND_CACHMENAGER_H
#define FINAL_PROJECT_SECOND_CACHMENAGER_H

#include <vector>

template <class problem,class solution>
class CachMenager {
    public:
        virtual  bool find_solution(problem) = 0;
        virtual solution get_solution(problem) = 0;
        //virtual void write_to_map(std::vector<solution> vec) = 0;
};


#endif //FINAL_PROJECT_SECOND_CACHMENAGER_H
