#include "Life.h"

int main() {
    return 0;
}

int Life::getWidth() {
    return this->width;
}

int Life::getHeight() {
    return this->height;
}

std::string Life::getName() {
    return this->name;
}

void Life::allocateMemoryForField() {
    field = new char*[this->height];
    if (field == nullptr) {
        throw std::length_error("Allocate Memory Error");
    }
    for (int i = 0; i < this->height; ++i) {
        field[i] = new char[this->width];
        if (field[i] == nullptr) {
            throw std::length_error("Allocate Memory Error");
        }
        for (int j = 0; j < this->width; ++j) {
            field[i][j] = 0;
        }
  }
} 

Life::Life() {
    this->width = 20;
    this->height = 20;
    this->name = "Standart Universe";
    this->survival.insert(2);
    this->survival.insert(3);
    this->birth.insert(3); 
    allocateMemoryForField();     
}

Life::Life(int width, int height, std::string name, 
    std::set<int> survival, std::set<int> birth) : 
        width(width), height(height), name(std::move(name)),
        survival(std::move(survival)), birth(std::move(birth)) {
            allocateMemoryForField();
}

Life::~Life() {
    if (field != nullptr) {
        for (int i = 0; i < this->height; ++i) {
            if (field[i] != nullptr) {
                delete[] field[i];
            } else {
                break;
            }
        }
    delete[] field;
  }
}

char& Life::operator()(int i, int j) {
  if (i >= this->height || j >= this->width) {
        throw std::length_error("Wrong Index");
  }
  return field[i][j];
}


void Life::newGeneration() {
    Life nextGeneration = Life(this->width, this->height, this->name, this->survival, this->birth);
    int countOfNeighbours = 0;
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            countOfNeighbours += (*this)((i + 1 + this->height) % this->height, (j - 1 + this->width) % this->width);
            countOfNeighbours += (*this)((i + 1 + this->height) % this->height, (j + 1 + this->width) % this->width);
            countOfNeighbours += (*this)((i - 1 + this->height) % this->height, (j - 1 + this->width) % this->width);
            countOfNeighbours += (*this)((i - 1 + this->height) % this->height, (j + 1 + this->width) % this->width);
            countOfNeighbours += (*this)((i + 1 + this->height) % this->height, j);
            countOfNeighbours += (*this)(i, (j + 1 + this->width) % this->width);
            countOfNeighbours += (*this)((i - 1 + this->height) % this->height, j);
            countOfNeighbours += (*this)(i, (j - 1 + this->width) % this->width);
            if (nextGeneration(i, j) == 1) {
                if ((this->survival).find(countOfNeighbours) != (this->survival).end()) {
                    nextGeneration(i, j) = 1;
                } else {
                    nextGeneration(i, j) = 0;
                }
            } else {
                if ((this->birth).find(countOfNeighbours) != (this->birth).end()) {
                    nextGeneration(i, j) = 1;
                }
            }
        }
    }
    for (int i = 0; i < this->height; ++i) {
        std::copy(nextGeneration.field[i], nextGeneration.field[i] + nextGeneration.width, field[i]);
    }
}