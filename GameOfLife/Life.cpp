#include "Life.h"

Cell::Cell(int x, int y) : x(x), y(y) {}

int Cell::getX() const { return x; }

int Cell::getY() const { return y; }

bool Life::operator()(int i, int j)  const {
    Cell needCell(i, j);
    if (this->livingCells.count(needCell) != 0) {
        return true;
    }
    return false;
}

bool Cell::operator<(const Cell &other) const {
    return x < other.x || (x == other.x && y < other.y);
}


void Life::newGeneration() {
    std::set<Cell> nextGeneration;
    int countOfNeighbours = 0;
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            countOfNeighbours = checkNeighbours(i, j);
            if ((*this)(i, j) == 1) {
                if ((this->survival).count(countOfNeighbours) != 0) {
                    Cell newCell(i, j);
                    nextGeneration.insert(newCell);
                }
            } else {
                if ((this->birth).count(countOfNeighbours) != 0) {
                    Cell newCell(i, j);
                    nextGeneration.insert(newCell);
                }
            }

            countOfNeighbours = 0;
        }
    }
    this->livingCells = nextGeneration;
}


int Life::checkNeighbours(int i, int j) const {
    int countOfNeighbours = 0;
    for (int k = -1; k < 2; k++) {
        for (int l = -1; l < 2; l++) {
            if (k == 0 && l == 0) {
                continue;
            } else if ((*this)((i + k  + this->height) % this->height, (j + l + this->width) % this->width)) {
                countOfNeighbours++;
            }
        }
    }
    return countOfNeighbours;
}