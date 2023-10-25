#ifndef FILEMANAGMENT_H_
#define FILEMANAGMENT_H_

#include <iostream>
#include <set>
#include "Life.h"


class FileManagment : public Life {
    private:
        void getCellFromFile(std::string line);
        void getSizeFromFile(std::string line);
        void getRuleFromFile(std::string line);
    public:
        FileManagment() = default;
        void getUniverseFromFile(std::string nameFile);
        void saveToFile(std::string nameFile);
        void printUniverse();
};


#endif