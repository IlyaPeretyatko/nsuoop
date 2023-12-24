#pragma once

#include <iostream>
#include <ostream>
#include <tuple>

template <typename Ch, typename Tr, typename T>
void printElem(std::basic_ostream<Ch, Tr>& os, size_t &index, const T& x) {
  if (index++ > 0) {
    os << ", ";
  }
  os << x;
}

template <typename Ch, typename Tr, size_t... Is>
auto& printTuple(std::basic_ostream<Ch, Tr>& os, const std::tuple<>&, std::index_sequence<Is...>) {
  return os;
}

template <typename Ch, typename Tr, typename ...Args, size_t... Is>
auto& printTuple(std::basic_ostream<Ch, Tr>& os, const std::tuple<Args...>& t, std::index_sequence<Is...>) {
  size_t index = 0;
  (printElem(os, index, std::get<Is>(t)), ...);
  return os;
}

template <typename Ch, typename Tr, typename ...Args, size_t TupSize = std::tuple_size<std::tuple<Args...>>::value>
auto& operator<<(std::basic_ostream<Ch, Tr>& os, const std::tuple<Args...>& t) {
  return printTuple(os, t, std::make_index_sequence<TupSize>{});
}