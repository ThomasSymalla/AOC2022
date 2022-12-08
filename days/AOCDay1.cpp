#include "AOCDay1.h"

#include <Helpers.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <sstream>
#include <thread>

namespace GDL
{

void AOCDay1::processDayInternal( std::istream& stream )
{
  std::string line;
  int current = 0;
  std::multiset< int > elves;
  while ( stream.good() )
  {
    std::getline( stream, line );
    if ( line.empty() )
    {
      elves.insert( current );
      if ( elves.size() >= 4 )
      {
        elves.erase( elves.begin() );
      }
      current = 0;
    }
    else
    {
      current += std::stoi( line );
    }
  }
  std::cout << "Highest Elf: " << *( --elves.end() ) << "\n";
  std::cout << "Top Three Elves: " << std::accumulate( elves.begin(), elves.end(), 0 ) << "\n";
}

} // namespace GDL
