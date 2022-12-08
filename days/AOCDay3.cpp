#include "AOCDay3.h"

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

void AOCDay3::processDayInternal( std::istream& stream )
{
  std::string line;
  int scorePart1 = 0, scorePart2 = 0;
  std::set< char > firstSet;
  std::set< char > secondSet;
  while ( stream.good() )
  {
    secondSet.clear();
    std::getline( stream, line );
    for ( int i = 0; i < line.size(); i++ )
    {
      secondSet.insert( line[i] );
    }
    for ( int i = 0; i < 2; i++ )
    {
      std::getline( stream, line );
      std::set< char > newSet;
      for ( int i = 0; i < line.size(); i++ )
      {
        auto find = secondSet.find( line[i] );
        if ( find != secondSet.end() )
        {
          newSet.insert(line[i]);
        }
      }
      secondSet = newSet;
    }
    char badge = *secondSet.begin();
    if (badge >= 'a' && badge <= 'z')
    {
      scorePart1 += static_cast<int>(badge) - 'a' + 1;
    }
    else
    {
      scorePart1 += static_cast<int>(badge) - 'A' + 27;
    }


    /*
    for ( int i = 0; i < line.size() / 2; i++ )
    {
      firstSet.insert( line[i] );
    }
    for ( int i = line.size() / 2; i < line.size(); i++ )
    {
      if ( firstSet.contains( line[i] ) )
      {
        if (line[i] >= 'a' && line[i] <= 'z' )
        {
          scorePart1 += static_cast< int >( line[i] ) - 'a' + 1;
        }
        else
        {
          scorePart1 += static_cast< int >( line[i] ) - 'A' + 27;
        }
        break;
      }
    }
    */
  }
  std::cout << "Final score for part 1: " << scorePart1 << "\n";
  std::cout << "Final score for part 2: " << scorePart2 << "\n";
}

} // namespace GDL
