#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <sstream>
#include <vector>

template < class T >
struct Range
{
public:
  Range()
  {
    mMin = 0;
    mMax = 0;
  }
  Range( T min, T max )
  {
    mMin = min;
    mMax = max;
  }
  int setMin( T min )
  {
    return mMin = min;
  }
  int setMax( T max )
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
  bool encompassesValue( T val )
  {
    return val >= mMin && val <= mMax;
  }
  bool encompassesRange( Range< T > range )
  {
    return range.getMin() >= mMin && range.getMax() <= mMax;
  }
  bool overlapsRange( Range< T > range )
  {
    auto check = []( Range< T > a, Range< T > b ) { return a.getMin() <= b.getMax() && b.getMin() <= a.getMax(); };
    return check( *this, range ) || check( range, *this );
  }

private:
  int mMin, mMax;
};

std::vector< std::string > splitByDelimiter( const std::string& input, const char& delimiter );

// std::vector< std::string > scrubLineForCriteria( const std::string& input, std::function< bool( char ) > criteria );

#endif