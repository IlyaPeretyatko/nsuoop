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
    std::string substr;
    std::string lineWithoutEscape = checkEscapeSymbol(line);
    std::stringstream ss(lineWithoutEscape);
    while (std::getline(ss, substr, columnSeparator_)) {
      tupleVector.push_back(substr);
    }
    if (tupleVector.size() != sizeof...(Args)) {
      throw std::length_error("Wrong Count Of Columns. Line:" + std::to_string(this->currentLine_));
    }
    return tupleVector;
  }

  std::string checkEscapeSymbol(const std::string & line) {
      size_t countEscapeSymbol = 0;
      int beginSubstr = 0;
      std::vector<std::string> betweenEscapeSymbol;
      for (size_t i = 0; i < line.length(); ++i) {
        if (line[i] == escapeSeparator_) {
          betweenEscapeSymbol.push_back(line.substr(beginSubstr, i - beginSubstr));
          beginSubstr = i + 1;
          ++countEscapeSymbol;
        }
      }
      betweenEscapeSymbol.push_back(line.substr(beginSubstr, line.length() - beginSubstr));
      if (countEscapeSymbol % 2 != 0) {
        throw std::length_error("Wrong Count Of Escape Symbols. Line: " + std::to_string(this->currentLine_) + ".");
      }
      std::string lineWithoutEscape;
      for (size_t i = 0; i <= countEscapeSymbol; i += 2) {
        lineWithoutEscape += betweenEscapeSymbol[i];
      }
      return lineWithoutEscape;
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
