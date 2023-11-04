#ifndef FILEMANAGMENT_H_
#define FILEMANAGMENT_H_

#include <iostream>
#include <set>
#include "Life.h"


class FileManagment : public Life {
    private:
        void getCellFromFile(const std::string & line);
        void getSizeFromFile(const std::string & line);
        void getRuleFromFile(const std::string & line);
    public:
        FileManagment() = default;
        void getUniverseFromFile(const std::string & path);
        void saveToFile(const std::string & path);
        void printUniverse();
};


#endif