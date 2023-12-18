#pragma once

#include <iostream>
#include <ostream>
#include <tuple>



template <typename Ch, typename Tr>
std::basic_ostream<Ch, Tr>& printTuple(std::basic_ostream<Ch, Tr>& os, const std::tuple<>&)
{
    return os;
}

template <typename Ch, typename Tr, typename T>
std::basic_ostream<Ch, Tr>& printTuple(std::basic_ostream<Ch, Tr>& os, const std::tuple<T> & t)
{
    os << std::get<0>(t);
    return os;
}

template <typename Ch, typename Tr, typename T, typename ...Args>
std::basic_ostream<Ch, Tr>& printTuple(std::basic_ostream<Ch, Tr>& os, std::tuple<T, Args...>const& t)
{
    os << std::get<0>(t);
    printTuple(os << ", ", std::tuple<Args...>(std::get<Args>(t)...));
    return os;
}

template<typename Ch, typename Tr, typename ...Args>
auto& operator<<(std::basic_ostream<Ch, Tr>& os, const std::tuple<Args...> & t)
{
    printTuple(os, t);
    return os;
}


