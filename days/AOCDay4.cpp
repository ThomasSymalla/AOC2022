#include "AOCDay4.h"

#include <Helpers.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <ranges>
#include <set>
#include <sstream>
#include <thread>

namespace GDL
{

std::pair< Range< int >, Range< int > > processLine( std::istream& stream )
{
  std::pair< Range< int >, Range< int > > toReturn;

  return toReturn;
}

void AOCDay4::processDayInternal( std::istream& stream )
{
  std::string line;
  int scorePart1 = 0, scorePart2 = 0;
  while ( stream.good() )
  {
    std::getline( stream, line );
    auto result = splitByDelimiter( line, ',' );
    auto leftRange = splitByDelimiter( result[0], '-' );
    auto rightRange = splitByDelimiter( result[1], '-' );
    Range< int > left( std::stoi( leftRange[0] ), std::stoi( leftRange[1] ) );
    Range< int > right( std::stoi( rightRange[0] ), std::stoi( rightRange[1] ) );
    if ( left.encompassesRange( right ) || right.encompassesRange( left ) )
    {
      scorePart1++;
    }
    if (left.overlapsRange(right) || right.overlapsRange(left))
    {
      scorePart2++;
    }
  }
  std::cout << "Final score for part 1: " << scorePart1 << "\n";
  std::cout << "Final score for part 2: " << scorePart2 << "\n";
}

} // namespace GDL
