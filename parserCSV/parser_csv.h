#pragma once

#include "print_tuple.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <limits>

template <typename ...Args>
class CSVParser {
public:
  class InputIterator;

  CSVParser(std::ifstream &file, size_t countLineSkip, char rowSeparator = '\n', char columnSeparator = ',', char escapeSeparator = '\"')
      : file_(file), countLineSkip_(countLineSkip), rowSeparator_(rowSeparator), columnSeparator_(columnSeparator), escapeSeparator_(escapeSeparator) {
    if (!file.is_open()) {
      // error
    }
    currentLine_ = 0;
    std::string lineSkip;
    for (size_t i = 0; i < countLineSkip_; ++i) {
      std::getline(file_, lineSkip, rowSeparator_);
    }
  }

  InputIterator begin() {
    file_.clear();
    file_.seekg(0, std::ifstream::beg);
    for (size_t i = 0; i < countLineSkip_; ++i) {
      file_.ignore(std::numeric_limits<std::streamsize>::max(), rowSeparator_);
    }
    return InputIterator(*this, InputIterator::Pointer::BEGIN);
  }

  InputIterator end() {
    return InputIterator(*this, InputIterator::Pointer::END);
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

  std::vector<std::string> getTupleOfLine(std::string &line) {
    std::vector<std::string> tupleVector;
    std::stringstream ss(line);
    std::string substr;
    while (std::getline(ss, substr, columnSeparator_)) {
      tupleVector.push_back(substr);
    }
    if (tupleVector.size() != sizeof...(Args)) {
      // error
    }
    return tupleVector;
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
class CSVParser<Args...>::InputIterator {
public:
  enum class Pointer
  {
    BEGIN,
    END
  };

  InputIterator(CSVParser<Args...>& father, Pointer point) : father_(father) {
    if (point == Pointer::BEGIN) {
      nextLine();
    } else {
      iter = nullptr;
    }
  }

  std::tuple<Args...> & operator*() const { return *iter; }

  const InputIterator operator++()
  {
    nextLine();
    return *this;
  }

  const InputIterator operator++(int) {
    const InputIterator temp = *this;
    nextLine();
    return temp;
  }

  bool operator==(const InputIterator &other) const { return (iter == other.iter); }

  bool operator!=(const InputIterator &other) const { return (iter != other.iter); }

private:
  CSVParser<Args...> & father_;
  std::shared_ptr<std::tuple<Args...>> iter;

  void nextLine() {
    std::string line = father_.getLine();
    if (line.empty()) {
      iter = nullptr;
    } else {
      iter = std::make_shared<std::tuple<Args...>>(makeTuple(father_.getTupleOfLine(line)));
    }
  }
};




