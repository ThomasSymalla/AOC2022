#include "Helpers.h"

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

std::vector< std::string > splitByDelimiter( const std::string& input, const char& delimiter )
{
  std::stringstream ss( input );
  std::vector< std::string > toReturn;
  while ( ss.good() )
  {
    std::string substr;
    std::getline( ss, substr, delimiter );
    toReturn.push_back( substr );
  }
  return toReturn;
}

// Given a function that returns true or false on each character, it splits the given string into segments based on that
// criteria. Adjacent charcaters that fit the criteria will be grouped together into strings, and all the strings will be returned
// in a vector.
std::vector< std::string > scrubLineForCriteria( const std::string& input, std::function< bool( char ) > criteria )
{
  std::vector< std::string > toReturn;
  int start = -1;
  for ( int i = 0; i < input.size(); i++ )
  {
    if ( criteria( input[i] ) )
    {
      if ( start == -1 )
      {
        start = i;
      }
    }
    else if ( start != -1 )
    {
      toReturn.push_back( input.substr( start, i - start ) );
      start = -1;
    }
  }
  if ( start != -1 )
  {
    toReturn.push_back( input.substr( start ) );
  }
  return toReturn;
}
