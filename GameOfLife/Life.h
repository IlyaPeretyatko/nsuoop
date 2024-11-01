#ifndef LIFE_H_
#define LIFE_H_

#include "Cell.h"
#include <iostream>
#include <set>


class Life {
    private:
        std::string name;
        int width;
        int height;
        std::set<int> survival;
        std::set<int> birth;
        std::set<Cell> livingCells;
        
        int checkNeighbours(int i, int j) const;
        bool operator()(int i, int j) const;
    public:
        Life() = default;
        void newGeneration();

        std::string getName() const;
        void setName(const std::string & name);
        int getWidth() const;
        void setWidth(const int & width);
        int getHeight() const;
        void setHeight(const int & height);
        std::set<int> getSurvival() const;
        void addSurvival(const int & i);
        std::set<int> getBirth() const;
        void addBirth(const int & i);
        void addCell(const int & i, const int & j);
        bool cellIsExists(const int & i, const int & j) const;
};


#endif