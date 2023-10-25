#include "AOCDay13.h"

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

struct Data
{
  virtual void Dummy() = 0;
};

struct DataInt : Data
{
  int value;
  DataInt( int value )
  {
    this->value = value;
  }
  void Dummy() override
  {
  }
};

struct DataList : Data
{
  std::vector< std::shared_ptr< Data > > values;
  void Dummy() override
  {
  }
};

std::shared_ptr< DataList > parseRecursive( const std::string& line, int& index )
{
  std::optional< int > currentInt = std::nullopt;
  auto currentDataList = std::make_shared< DataList >();
  for ( ; index < line.size(); index++ )
  {
    if ( line[index] == '[' )
    {
      index++;
      auto newDataList = parseRecursive( line, index );
      currentDataList->values.push_back( newDataList );
    }
    else if ( line[index] == ']' )
    {
      if ( currentInt.has_value() )
      {
        currentDataList->values.push_back( std::make_shared< DataInt >( *currentInt ) );
      }
      return currentDataList;
    }
    else if ( line[index] == ',' )
    {
      if ( currentInt.has_value() )
      {
        currentDataList->values.push_back( std::make_shared< DataInt >( *currentInt ) );
        currentInt = std::nullopt;
      }
    }
    else
    {
      if ( !currentInt.has_value() )
      {
        currentInt = 0;
      }
      *currentInt *= 10;
      *currentInt += line[index] - '0';
    }
  }
  return currentDataList;
}

std::shared_ptr< DataList > parse( const std::string& line )
{
  int indexObj = 1;
  return parseRecursive( line, indexObj );
}

std::optional< bool > orderIsCorrectRecursive( std::shared_ptr< DataList > first, std::shared_ptr< DataList > second )
{
  int iterations = std::max( first->values.size(), second->values.size() );
  for ( int i = 0; i < iterations; i++ )
  {
    if ( i >= first->values.size() )
    {
      return true;
    }
    else if ( i >= second->values.size() )
    {
      return false;
    }
    auto left = first->values[i];
    auto right = second->values[i];

    auto leftCastList = std::dynamic_pointer_cast< DataList >( left );
    auto rightCastList = dynamic_pointer_cast< DataList >( right );
    auto leftCastInt = dynamic_pointer_cast< DataInt >( left );
    auto rightCastInt = dynamic_pointer_cast< DataInt >( right );
    if ( leftCastInt && rightCastInt )
    {
      if ( leftCastInt->value > rightCastInt->value )
      {
        return false;
      }
      else if ( leftCastInt->value < rightCastInt->value )
      {
        return true;
      }
    }
    else
    {
      std::shared_ptr< DataList > leftList;
      std::shared_ptr< DataList > rightList;
      if ( leftCastList )
      {
        leftList = leftCastList;
      }
      else
      {
        leftList = std::make_shared< DataList >();
        leftList->values.push_back( std::make_shared< DataInt >( leftCastInt->value ) );
      }
      if ( rightCastList )
      {
        rightList = rightCastList;
      }
      else
      {
        rightList = std::make_shared< DataList >();
        rightList->values.push_back( std::make_shared< DataInt >( rightCastInt->value ) );
      }
      auto result = orderIsCorrectRecursive( leftList, rightList );
      if ( result != std::nullopt )
      {
        return result.value();
      }
    }
  }
  return std::nullopt;
}

bool orderIsCorrect( std::shared_ptr< DataList > first, std::shared_ptr< DataList > second )
{
  return orderIsCorrectRecursive( first, second ).value();
}

void AOCDay13::processDayInternal( std::istream& stream )
{
  std::string line;
  int index = 1, part1 = 0;
  std::vector< std::shared_ptr< DataList > > packets;
  while ( stream.good() )
  {
    std::getline( stream, line );
    std::shared_ptr< DataList > first = parse( line );
    packets.push_back( first );
    std::getline( stream, line );
    std::shared_ptr< DataList > second = parse( line );
    packets.push_back( second );

    if ( orderIsCorrect( first, second ) )
    {
      part1 += index;
    }
    std::getline( stream, line );
    index++;
  }
  auto dpA = std::make_shared< DataList >();
  auto dpA2 = std::make_shared< DataList >();
  dpA2->values.push_back( std::make_shared< DataInt >( 2 ) );
  dpA->values.push_back( dpA2 );
  auto dpB = std::make_shared< DataList >();
  auto dpB6 = std::make_shared< DataList >();
  dpB6->values.push_back( std::make_shared< DataInt >( 6 ) );
  dpB->values.push_back( dpB6 );
  packets.push_back( dpA );
  packets.push_back( dpB );
  while ( true )
  {
    bool isDone = true;
    for ( int i = 0; i < packets.size() - 1; i++ )
    {
      if ( !orderIsCorrect( packets[i], packets[i + 1] ) )
      {
        std::swap( packets[i], packets[i + 1] );
        isDone = false;
      }
    }
    if ( isDone )
    {
      break;
    }
  }
  auto iterA = std::find( packets.begin(), packets.end(), dpA );
  auto iterB = std::find( packets.begin(), packets.end(), dpB );
  int part2 = ( ( iterA - packets.begin() ) + 1 ) * ( ( iterB - packets.begin() ) + 1 );
  std::cout << "Part1: " << part1 << "\n";
  std::cout << "Part2: " << part2 << "\n";
}

} // namespace GDL
