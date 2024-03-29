#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <limits>
#include <regex>

template <typename ...Args>
class CSVParser {
public:
  class Iterator;

  CSVParser(std::ifstream &file, size_t countLineSkip, char rowSeparator = '\n', char columnSeparator = ',', char escapeSeparator = '\"')
      : file_(file), countLineSkip_(countLineSkip), rowSeparator_(rowSeparator), columnSeparator_(columnSeparator), escapeSeparator_(escapeSeparator), currentLine_(0) {
    if (!file.is_open()) {
      throw std::length_error("File Not Open.");
    }
  }

  Iterator begin() {
    std::string lineSkip;
    for (size_t i = 0; i < countLineSkip_; ++i) {
      std::getline(file_, lineSkip, rowSeparator_);
    }
    return Iterator(*this, 1);
  }

  Iterator end() {
    return Iterator(*this, 0);
  }

private:
  std::ifstream &file_;
  size_t countLineSkip_;
  char rowSeparator_;
  char columnSeparator_;
  char escapeSeparator_;
  size_t currentLine_;

  std::string getLine() {
    std::string line;
    getline(file_, line, rowSeparator_);
    currentLine_++;
    return line;
  }

  std::vector<std::string> getTupleOfLine(const std::string &line) {
    std::vector<std::string> tupleVector;
    size_t beginSubstr = 0;
    bool isEscape = false;
    for (size_t i = 0; i < line.length(); ++i) {
      if (line[i] == escapeSeparator_) {
        isEscape = (isEscape) ? false: true;
      }
      if (line[i] == columnSeparator_ && isEscape == false) {
        tupleVector.push_back(line.substr(beginSubstr, i - beginSubstr));
        beginSubstr = i + 1;
      }
    }
    tupleVector.push_back(line.substr(beginSubstr, line.length() - beginSubstr));
    if (tupleVector.size() != sizeof...(Args)) {
      throw std::length_error("Wrong Count Of Columns. Line:" + std::to_string(this->currentLine_));
    }
    tupleVector = deleteEscapeSymbols(tupleVector);
    return tupleVector;
  }

  std::vector<std::string> deleteEscapeSymbols(const std::vector<std::string> & tupleVector) {
    std::vector<std::string> returnTupleVector;
    for (size_t column = 0; column < tupleVector.size(); ++column) {
      size_t countEscapeSymbol = 0;
      int beginSubstr = 0;
      std::vector<std::string> tmpTupleVector;
      for (size_t i = 0; i < tupleVector[column].length(); ++i) {
        if (tupleVector[column][i] == escapeSeparator_) {
          tmpTupleVector.push_back(tupleVector[column].substr(beginSubstr, i - beginSubstr));
          beginSubstr = i + 1;
        }
      }
      tmpTupleVector.push_back(tupleVector[column].substr(beginSubstr, tupleVector[column].length() - beginSubstr));
      if (countEscapeSymbol % 2 != 0) {
        throw std::length_error("Wrong Count Of Escape Symbols. Line: " + std::to_string(this->currentLine_) + ". Column: " + std::to_string(column) + ".");
      }
      std::string elemOfTuple = "";
      for (auto j : tmpTupleVector) {
        elemOfTuple += j;
      }
      returnTupleVector.push_back(elemOfTuple);
    }
    return returnTupleVector;
  }

};

template <typename T>
T convert(const std::string str) {
  std::istringstream iss(str);
  T value;
  iss >> value;
  return value;
}

template <typename ...Args, size_t ...Iters>
std::tuple<Args...> makeTupleHelper(std::vector<std::string> params, std::index_sequence<Iters...>) {
  return std::make_tuple(convert<Args>(params[Iters])...);
}

template <typename ...Args>
std::tuple<Args...> makeTuple(std::vector<std::string> params) {
  return makeTupleHelper<Args...>(params, std::index_sequence_for<Args...>{});
}

template <typename ...Args>
class CSVParser<Args...>::Iterator {
public:
  Iterator(CSVParser<Args...>& father, bool isBegin) : father_(father) {
    if (isBegin) {
      nextLine();
    } else {
      iter = nullptr;
    }
  }

  std::tuple<Args...> & operator*() const { return *iter; }

  const Iterator operator++()
  {
    nextLine();
    return *this;
  }

  bool operator==(const Iterator &other) const { return (iter == other.iter); }

  bool operator!=(const Iterator &other) const { return (iter != other.iter); }

private:
  CSVParser<Args...> & father_;
  std::shared_ptr<std::tuple<Args...>> iter;

  void nextLine() {
    std::string line = father_.getLine();
    if (line.empty()) {
      iter = nullptr;
    } else {
      iter = std::make_shared<std::tuple<Args...>>(makeTuple<Args...>(father_.getTupleOfLine(line)));
    }
  }
};
