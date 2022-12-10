#include "AOCDay8.h"

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

namespace GDL
{

bool visibilityCheck( std::vector< std::vector< int > >& sizeMap, int& i, int& j )
{
  int treeHeight = sizeMap[i][j];
  bool visible = true;

  for ( int x = 0; x < i; x++ )
  {
    if ( sizeMap[x][j] >= treeHeight )
    {
      visible = false;
    }
  }
  if ( visible ) return true;
  visible = true;

  for ( int x = i + 1; x < sizeMap.size(); x++ )
  {
    if ( sizeMap[x][j] >= treeHeight )
    {
      visible = false;
    }
  }
  if ( visible ) return true;
  visible = true;

  for ( int y = 0; y < j; y++ )
  {
    if ( sizeMap[i][y] >= treeHeight )
    {
      visible = false;
    }
  }
  if ( visible ) return true;
  visible = true;

  for ( int y = j + 1; y < sizeMap[0].size(); y++ )
  {
    if ( sizeMap[i][y] >= treeHeight )
    {
      visible = false;
    }
  }
  if ( visible ) return true;
  visible = true;

  return false;
}

int treeScore( std::vector< std::vector< int > >& sizeMap, int& i, int& j )
{
  int treeHeight = sizeMap[i][j];
  int finalScore = 0;
  int score = 0;
  for ( int x = i - 1; x >= 0; x-- )
  {
    score++;
    if ( sizeMap[x][j] >= treeHeight )
    {
      break;
    }
  }
  finalScore = score;
  score = 0;
  for ( int x = i + 1; x < sizeMap.size(); x++ )
  {
    score++;
    if ( sizeMap[x][j] >= treeHeight )
    {
      break;
    }
  }
  finalScore *= score;
  score = 0;
  for ( int y = j - 1; y >= 0; y-- )
  {
    score++;
    if ( sizeMap[i][y] >= treeHeight )
    {
      break;
    }
  }
  finalScore *= score;
  score = 0;
  for ( int y = j + 1; y < sizeMap[0].size(); y++ )
  {
    score++;
    if ( sizeMap[i][y] >= treeHeight )
    {
      break;
    }
  }
  finalScore *= score;
  return finalScore;
}

void AOCDay8::processDayInternal( std::istream& stream )
{
  std::string line;

  std::vector< std::vector< int > > sizeMap;
  while ( stream.good() )
  {
    std::getline( stream, line );
    std::vector< int > row;
    for ( int i = 0; i < line.size(); i++ )
    {
      row.push_back( line[i] - '0' );
    }
    sizeMap.push_back( row );
  }

  int part1 = 0;
  int part2 = -1;
  for ( int i = 0; i < sizeMap.size(); i++ )
  {
    for ( int j = 0; j < sizeMap[0].size(); j++ )
    {
      part2 = std::max( part2, treeScore( sizeMap, i, j ) );
      if ( visibilityCheck( sizeMap, i, j ) )
      {
        part1++;
      }
    }
  }
  std::cout << "Part 1: " << part1 << "\n";
  std::cout << "Part 2: " << part2 << "\n";
}

} // namespace GDL
