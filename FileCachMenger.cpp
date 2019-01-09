#include "FileCachMenger.h"

FileCachMenger::FileCachMenger()
{
    this->flg = false;
}

bool FileCachMenger:: find_solution(std::string problem)
{
    //check if the problem is in the map
    std::unordered_map<std::string,std::string> :: iterator it;
    it = this->hash_map.find(problem);
    //if yes return true
    if(it != this->hash_map.end())
    {
        return true;
    }
    //if not and the hashmap is
    if(this->flg)
    {
       return false;
    }

}
std::string FileCachMenger:: get_solution(std::string problem)
{

}

void FileCachMenger::add_solution(std::string solution)
{
    this->vec.push_back(solution);
}
