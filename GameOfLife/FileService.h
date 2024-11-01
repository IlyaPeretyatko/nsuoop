#ifndef FILEMANAGMENT_H_
#define FILEMANAGMENT_H_

#include "Life.h"
#include <iostream>
#include <set>


class FileService {
    private:
        Life * life;
        void getCellFromFile(const std::string & line);
        void getSizeFromFile(const std::string & line);
        void getRuleFromFile(const std::string & line);
    public:
        FileService(Life * life);
        void getUniverseFromFile(const std::string & path);
        void saveToFile(const std::string & path) const;
        void printUniverse() const;
};


#endif