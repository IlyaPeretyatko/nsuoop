#include "Life.h"
#include <fstream>

Life::Life() : width(0), height(0), name("") {
    field = nullptr;
}

Life::Life(int width, int height) : width(width), height(height) {
    allocateMemoryForField();
}

void Life::allocateMemoryForField() {
    field = new unsigned char*[this->height];
    if (field == nullptr) {
        throw std::length_error("Allocate Memory Error");
    }
    for (int i = 0; i < this->height; ++i) {
        field[i] = new unsigned char[this->width];
        if (field[i] == nullptr) {
            throw std::length_error("Allocate Memory Error");
        }
        for (int j = 0; j < this->width; ++j) {
            field[i][j] = 0;
        }
  }
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

unsigned char& Life::operator()(int i, int j) {
  if (i >= this->height || j >= this->width) {
        throw std::length_error("Wrong Index");
  }
  return field[i][j];
}


void Life::newGeneration() {
    Life nextGeneration(this->width, this->height);
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
            if ((*this)(i, j) == 1) {
                if ((this->survival).count(countOfNeighbours) != 0) {
                    nextGeneration(i, j) = 1;
                } else {
                    nextGeneration(i, j) = 0;
                }
            } else {
                if ((this->birth).count(countOfNeighbours) != 0) {
                    nextGeneration(i, j) = 1;
                }
            }
            countOfNeighbours = 0;
        }
    }
    for (int i = 0; i < this->height; ++i) {
        std::copy(nextGeneration.field[i], nextGeneration.field[i] + nextGeneration.width, field[i]);
    }
}

void Life::getUniverseFromFile(std::string nameFile) {
    std::string path = "../examples/";
    path += nameFile;
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::length_error("File Not Open");
    }
    std::string line;
    while(std::getline(file, line, '\n')) {
        if (line[0] == '#' && line[1] == 'N' && line[2] == ' ') {
            for (int i = 3; i < (int)line.size(); ++i) {
                this->name += line[i];
            }
        } else if (line[0] == '#' && line[1] == 'R' && line[2] == ' ') {
            bool readB = true;
            for (int i = 3; i < (int)line.size(); ++i) {
                if (line[i] == 'S') {
                    readB = false;
                } else if (line[i] >= '0' && line[i] <= '9') {
                    if (readB) {
                        this->birth.insert((unsigned char)line[i] - '0');
                    } else {
                        this->survival.insert((unsigned char)line[i] - '0');
                    }
                }
            }
        } else if (line[0] == '#' && line[1] == 'S' && line[2] == ' ') {
            std::string w = "";
            std::string h = "";
            bool readW = true;  
            for (int i = 3; i < (int)line.size(); ++i) {
                if (line[i] == '/') {
                    readW = false;
                } else if (line[i] >= '0' && line[i] <= '9') {
                    if (readW) {
                        w += line[i];
                    } else {
                        h += line[i];
                    }
                }
            }
            this->width = stoi(w);
            this->height = stoi(h);
            allocateMemoryForField();
        } else if (line[0] == '#') {
            continue;
        } else {
            std::string x = "";
            std::string y = "";
            bool readX = true;
            for (int i = 0; i < (int)line.size(); ++i) {
                if (line[i] == ' ') {
                    readX = false;
                    continue;
                }
                if (readX) {
                    x += line[i];
                } else {
                    y += line[i];
                }
            }
            this->field[std::stoi(x)][std::stoi(y)] = 1;
        }
    }
    file.close();
}

void Life::saveToFile(std::string nameFile) {
    std::string path = "../";
    path += nameFile;
    std::ofstream fout(path);
    if (!fout.is_open()) {
        throw std::length_error("File Not Open");
    }
    fout << "#Life 1.06" << std::endl;
    fout << "#N " << this->name << std::endl;
    fout << "#R " << "B";
    for (auto& it: this->birth) {
        fout << it;
    }
    fout << "/S";
    for (auto& it: this->survival) {
        fout << it;
    }
    fout << std::endl << "#S ";
    fout << this->width << "/" << this->height << std::endl;
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            if (field[i][j]) {
                fout << i << " " << j << std::endl;
            }
        }
    }
    fout.close();
}