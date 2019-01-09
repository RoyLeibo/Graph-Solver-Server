
#ifndef FINAL_PROJECT_SECOND_FILECACHMENGER_H
#define FINAL_PROJECT_SECOND_FILECACHMENGER_H

#include "CachMenager.h"
#include "string"
#include <unordered_map>
#include <vector>
#include <fstream>

class FileCachMenger : public CachMenager<std::string,std::string> {
    private:
        std::unordered_map<std::string,std::string> hash_map;
        bool flg;
        std::vector<std::string> vec;
        std::fstream solution_file;
    public:
        FileCachMenger();
        virtual bool find_solution(std::string problem);
        virtual std::string get_solution(std::string problem);
        void add_solution(std::string solution);
};


#endif //FINAL_PROJECT_SECOND_FILECACHMENGER_H
