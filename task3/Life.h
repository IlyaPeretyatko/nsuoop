#ifndef LIFE_H_
#define LIFE_H_

#include <iostream>
#include <set>
#include <vector>

class Cell {
    private:
        int x;
        int y;
    public:
        Cell() = default;
        Cell(int x, int y);
        int getX();
        int getY();
};

class Life {
    protected:
        int width;
        int height;
        std::string name;
        std::set<int> survival;
        std::set<int> birth;
        std::vector<Cell> field;
    public:
        Life() = default;
        void newGeneration();
        int checkNeighbours(int i, int j, int x, int y);
        bool operator()(int i, int j);
};


#endif