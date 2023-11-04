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
            for (auto it: this->livingCells) {
                countOfNeighbours += checkNeighbours(i, j, it.getX(), it.getY());
            }
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


int Life::checkNeighbours(int i, int j, int x, int y) {
    int countOfNeighbours = 0;
    if (x == (i + 1 + this->height) % this->height && y == (j - 1 + this->width) % this->width) {
        countOfNeighbours++;
    }
    if (x == (i + 1 + this->height) % this->height && y == (j + 1 + this->width) % this->width) {
        countOfNeighbours++;
    }
    if (x == (i - 1 + this->height) % this->height && y == (j - 1 + this->width) % this->width) {
        countOfNeighbours++;
    }
    if (x == (i - 1 + this->height) % this->height && y == (j + 1 + this->width) % this->width) {
        countOfNeighbours++;
    }
    if (x == (i + 1 + this->height) % this->height && y == j) {
        countOfNeighbours++;
    }
    if (x == (i - 1 + this->height) % this->height && y == j) {
        countOfNeighbours++;
    }
    if (x == i && y == (j + 1 + this->width) % this->width) {
        countOfNeighbours++;
    }
    if (x == i && y == (j - 1 + this->width) % this->width) {
        countOfNeighbours++;
    }
    return countOfNeighbours;
}