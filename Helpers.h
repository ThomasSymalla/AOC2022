#ifndef HELPERS_H
#define HELPERS_H

#include <chrono>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <sstream>
#include <thread>

std::vector< std::string > splitByDelimiter( const std::string& input, const char& delimiter );

std::vector< std::string > scrubLineForCriteria( const std::string& input, std::function< bool( char ) > criteria );

static const std::function< bool(char) > isLetter = [](char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
};

static const std::function< bool(char) > isNumber = [](char c) {
  return c >= '0' && c <= '9';
};


template < typename T>
int getSign(T input)
{
  return (input > 0) - (input < 0);
}

template < class T >
struct Range
{
public:
  Range()
  {
    mMin = 0;
    mMax = 0;
  }
  Range(T min, T max)
  {
    mMin = min;
    mMax = max;
  }
  int setMin(T min)
  {
    return mMin = min;
  }
  int setMax(T max)
  {
    return mMax = max;
  }
  int getMin()
  {
    return mMin;
  }
  int getMax()
  {
    return mMax;
  }
  bool encompassesValue(T val)
  {
    return val >= mMin && val <= mMax;
  }
  bool encompassesRange(Range< T > range)
  {
    return range.getMin() >= mMin && range.getMax() <= mMax;
  }
  bool overlapsRange(Range< T > range)
  {
    auto check = [](Range< T > a, Range< T > b) { return a.getMin() <= b.getMax() && b.getMin() <= a.getMax(); };
    return check(*this, range) || check(range, *this);
  }

private:
  int mMin, mMax;
};

#endif