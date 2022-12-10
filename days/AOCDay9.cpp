#include "AOCDay9.h"

#include <Helpers.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_set>

namespace GDL
{

uint64_t pairToLong( std::pair< int, int > input )
{
  return ( static_cast< uint64_t >( input.first ) << 32 ) + static_cast< uint64_t >( input.second );
}

bool ropeSegmentsTooFarAway( const std::pair< int, int >& front, const std::pair< int, int >& back )
{
  return std::abs( front.first - back.first ) > 1 || std::abs( front.second - back.second ) > 1;
}

void moveRopeConnection( std::pair< int, int >& front, std::pair< int, int >& back )
{
  int xOffset = front.first - back.first;
  int yOffset = front.second - back.second;
  if ( xOffset != 0 )
  {
    back.first += 1 * getSign( xOffset );
  }
  if ( yOffset != 0 )
  {
    back.second += 1 * getSign( yOffset );
  }
}

// Today's problem is a fairly simple simulation. Rope segments are stored in a vector of coordinates,
// and when we move the head we recursively check down the rope to see if updates are necessary.
// Also, in order to store visited indexes of the tail, we hash the pair into a long.
void AOCDay9::processDayInternal( std::istream& stream )
{
  const int ropeSize = 10;
  std::string line;
  std::vector< std::pair< int, int > > rope;
  std::unordered_set< uint64_t > visited;
  std::map< char, std::pair< int, int > > directions = {
    { 'U', std::pair< int, int >( 0, 1 ) },
    { 'D', std::pair< int, int >( 0, -1 ) },
    { 'L', std::pair< int, int >( -1, 0 ) },
    { 'R', std::pair< int, int >( 1, 0 ) } };

  for ( int i = 0; i < ropeSize; i++ )
  {
    rope.push_back( std::pair< int, int >( 0, 0 ) );
  }

  while ( stream.good() )
  {
    std::getline( stream, line );
    auto split = splitByDelimiter( line, ' ' );
    auto direction = directions[split[0][0]];
    int movementLength = stoi( split[1] );
    for ( int i = 0; i < movementLength; i++ )
    {
      rope[0].first += direction.first;
      rope[0].second += direction.second;

      for ( int i = 1; i < rope.size(); i++ )
      {
        if ( ropeSegmentsTooFarAway( rope[i - 1], rope[i] ) )
        {
          moveRopeConnection( rope[i - 1], rope[i] );
        }
        else
        {
          break;
        }
      }

      visited.insert( pairToLong( rope[rope.size() - 1] ) );
    }
  }

  std::cout << "Spots tail visited: " << visited.size() << "\n";
}

} // namespace GDL
