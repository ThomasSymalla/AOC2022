#include "AOCDay12.h"

#include <Helpers.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_set>

namespace GDL
{

int getShortestPath( const std::vector< std::vector< int > >& heightMap, const Coords& start, const Coords& finish )
{
  std::vector< std::vector< int > > visitedMap( heightMap.size(), std::vector< int >( heightMap[0].size(), INT_MAX ) );
  std::queue< std::pair< Coords, int > > toCheck;
  toCheck.push( std::pair< Coords, int >( start, 0 ) );

  while ( toCheck.size() )
  {
    auto& current = toCheck.front();
    toCheck.pop();
    for ( auto direction : cardinalDirections )
    {
      auto newPos = current.first + direction;
      if ( newPos.x >= 0 && newPos.x < heightMap.size() && newPos.y >= 0 && newPos.y < heightMap[0].size() )
      {
        int oldHeight = heightMap[current.first.x][current.first.y];
        int newHeight = heightMap[newPos.x][newPos.y];
        if ( newHeight <= oldHeight + 1 )
        {
          if ( newPos.x == finish.x && newPos.y == finish.y )
          {
            return current.second + 1;
          }
          else if ( visitedMap[newPos.x][newPos.y] > current.second + 1 )
          {
            visitedMap[newPos.x][newPos.y] = current.second + 1;
            toCheck.push( std::pair< Coords, int >( newPos, current.second + 1 ) );
          }
        }
      }
    }
  }
  return INT_MAX;
}

void AOCDay12::processDayInternal( std::istream& stream )
{

  std::vector< std::vector< int > > heightMap;
  Coords finish;

  std::vector< Coords > startingPositions;

  std::string line;
  int i = 0;
  while ( stream.good() )
  {
    std::getline( stream, line );
    std::vector< int > newRow;
    for ( int j = 0; j < line.size(); j++ )
    {
      if ( line[j] == 'S' || line[j] == 'a' )
      {
        startingPositions.push_back( Coords( i, j ) );
        newRow.push_back( 'a' - 'a' );
      }
      else if ( line[j] == 'E' )
      {
        finish.x = i;
        finish.y = j;
        newRow.push_back( 'z' - 'a' );
      }
      else
      {
        int q = line[j] - 'a';
        newRow.push_back( q );
      }
    }
    heightMap.push_back( newRow );
    i++;
  }

  int shortestPath = INT_MAX;
  for ( auto start : startingPositions )
  {
    shortestPath = std::min( shortestPath, getShortestPath( heightMap, start, finish ) );
  }
  std::cout << "Shortest path: " << shortestPath << "\n";
}

} // namespace GDL
