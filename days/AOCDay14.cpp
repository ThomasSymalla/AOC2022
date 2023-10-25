#include "AOCDay14.h"

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

int xMin = INT_MAX, xMax = INT_MIN, yMin = INT_MAX, yMax = INT_MIN, xSize, ySize;

bool gridBoundaryCheck( const Coords& test )
{
  int yConverted = test.y - yMin;
  int xConverted = test.x - xMin;
  return ( yConverted >= 0 && yConverted < ySize ) && ( xConverted >= 0 && xConverted < xSize );
}

void AOCDay14::processDayInternal( std::istream& stream )
{
  std::string line;
  std::vector< std::vector< Coords > > paths;
  while ( stream.good() )
  {
    std::getline( stream, line );
    auto splitDash = splitByDelimiter( line, '-' );
    std::vector< Coords > path;
    for ( auto& node : splitDash )
    {
      auto splitInts = splitIntoInts( node );
      path.push_back( Coords( splitInts[0], splitInts[1] ) );
    }
    paths.push_back( path );
  }



  //Part 1
  /* 
  for ( const auto& path : paths )
  {
    for ( const auto& coord : path )
    {
      xMin = std::min( xMin, coord.x );
      xMax = std::max( xMax, coord.x );
      // yMin = std::min(yMin, coord.y);
      yMax = std::max( yMax, coord.y );
    }
  } 
  yMin = 0;
  xSize = xMax - xMin + 1;
  ySize = yMax - yMin + 1;
  std::vector< std::vector< char > > map( ySize, std::vector< char >( xSize, '.' ) );
  for ( const auto& path : paths )
  {
    for ( int i = 0; i < static_cast< int >( path.size() ) - 1; i++ )
    {
      const Coords& first = path[i];
      const Coords& second = path[i + 1];
      if ( first.x == second.x )
      {
        int x = first.x;
        int lowerY = std::min( first.y, second.y );
        int higherY = std::max( first.y, second.y );
        for ( int y = lowerY; y <= higherY; y++ )
        {
          map[y - yMin][x - xMin] = '#';
        }
      }
      else
      {
        int y = first.y;
        int lowerX = std::min( first.x, second.x );
        int higherX = std::max( first.x, second.x );
        for ( int x = lowerX; x <= higherX; x++ )
        {
          map[y - yMin][x - xMin] = '#';
        }
      }
    }
  }
  Coords sandStartingPos( 500, 0 );
  bool abyssHit = false;
  const std::vector<Coords> offsets = { Coords(0,1), Coords(-1,1), Coords(1,1) };
  int sandCount = 0;
  while ( !abyssHit )
  {
    Coords currentSandPos( sandStartingPos );
    while ( true )
    {
      Coords testSandPos;
      bool sandMoved = false;

      for (const auto& offset : offsets) {
        testSandPos = currentSandPos + offset;
        if (!gridBoundaryCheck(testSandPos))
        {
          abyssHit = true;
          break;
        }
        else if (map[testSandPos.y - yMin][testSandPos.x - xMin] == '.')
        {
          currentSandPos = testSandPos;
          sandMoved = true;
          break;
        }
      }
      if (abyssHit) {
        break;
      }
      else if (!sandMoved) {
        map[currentSandPos.y - yMin][currentSandPos.x - xMin] = 'o';
        sandCount++;
        break;
      }
    }
  }*/
  for (const auto& path : paths)
  {
    for (const auto& coord : path)
    {
      //xMin = std::min(xMin, coord.x);
      //xMax = std::max(xMax, coord.x);
      // yMin = std::min(yMin, coord.y);
      yMax = std::max(yMax, coord.y);
    }
  }
  yMin = 0;
  ySize = yMax - yMin + 3;
  xMin = 500 - (1 + (ySize-2)*2);
  xMax = 500 + (1 + (ySize - 2) * 2);
  xSize = xMax - xMin + 1;

  std::vector< std::vector< char > > map(ySize, std::vector< char >(xSize, '.'));
  for (const auto& path : paths)
  {
    for (int i = 0; i < static_cast<int>(path.size()) - 1; i++)
    {
      const Coords& first = path[i];
      const Coords& second = path[i + 1];
      if (first.x == second.x)
      {
        int x = first.x;
        int lowerY = std::min(first.y, second.y);
        int higherY = std::max(first.y, second.y);
        for (int y = lowerY; y <= higherY; y++)
        {
          map[y - yMin][x - xMin] = '#';
        }
      }
      else
      {
        int y = first.y;
        int lowerX = std::min(first.x, second.x);
        int higherX = std::max(first.x, second.x);
        for (int x = lowerX; x <= higherX; x++)
        {
          map[y - yMin][x - xMin] = '#';
        }
      }
    }
  }
  for (int x = 0; x < map[0].size(); x++) {
    map[map.size() - 1][x] = '#';
  }

  Coords sandStartingPos(500, 0);
  bool abyssHit = false;
  const std::vector<Coords> offsets = { Coords(0,1), Coords(-1,1), Coords(1,1) };
  int sandCount = 0;
  while (!abyssHit)
  {
    Coords currentSandPos(sandStartingPos);
    while (true)
    {
      Coords testSandPos;
      bool sandMoved = false;

      for (const auto& offset : offsets) {
        testSandPos = currentSandPos + offset;
        if (!gridBoundaryCheck(testSandPos))
        {
          abyssHit = true;
          break;
        }
        else if (map[testSandPos.y - yMin][testSandPos.x - xMin] == '.')
        {
          currentSandPos = testSandPos;
          sandMoved = true;
          break;
        }
      }
      if (abyssHit) {
        break;
      }
      else if (!sandMoved) {
        map[currentSandPos.y - yMin][currentSandPos.x - xMin] = 'o';
        sandCount++;
        if (currentSandPos == sandStartingPos) {
          abyssHit = true;
        }
        break;
      }
    }
  }

  /*for (int x = 0; x < map.size(); x++)
  {
    for ( int y = 0; y < map[0].size(); y++ )
    {
      std::cout << map[x][y];
    }
    std::cout << "\n";
  }
  std::cout << "Sandcount: " << sandCount << "\n";
  */
}

} // namespace GDL
