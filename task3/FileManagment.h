#ifndef FILEMANAGMENT_H_
#define FILEMANAGMENT_H_

#include <iostream>
#include <set>
#include "Life.h"


class FileManagment : public Life {
    private:

    public:
        FileManagment() = default;
        void getUniverseFromFile(std::string nameFile);
        void saveToFile(std::string nameFile);
        void printUniverse();
};


#endif