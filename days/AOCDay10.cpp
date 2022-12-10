#include "AOCDay10.h"

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

struct Command
{
  int cyclesRemaining;

  virtual void perform( int& reg ) = 0;
};

struct Noop : Command
{
  Noop() {
    cyclesRemaining = 1;
  }
  void perform( int& reg ){};
};

struct AddX : Command
{
  int value;

  AddX( int value ) : Command()
  {
    this->value = value;
    cyclesRemaining = 2;
  }

  void perform( int& reg )
  {
    reg += value;
  };
};

struct ElfCPU
{
  int cycleNum = 1;
  int X = 1;

  std::shared_ptr< Command > currentCommand;
  std::vector< std::shared_ptr< Command > > commandQueue;

  void progressCycle()
  {
    if ( commandQueue.size() && !currentCommand )
    {
      currentCommand = commandQueue[0];
      commandQueue.erase( commandQueue.begin() );
    }
    draw();
    if ( currentCommand )
    {
      currentCommand->cyclesRemaining--;
      if ( currentCommand->cyclesRemaining <= 0 )
      {
        currentCommand->perform( X );
        currentCommand = nullptr;
      }
      cycleNum++;
    }
  }

  void draw()
  {
    int columnNumber = cycleNum % 40 - 1;
    if ( columnNumber == 0 ) std::cout << "\n";
    std::cout << ( std::abs( columnNumber - X) <= 1 ? "#" : "." );
  }

  int signalStrength()
  {
    return cycleNum * X;
  }
};

void AOCDay10::processDayInternal( std::istream& stream )
{
  std::string line;
  ElfCPU elfCPU;
  while ( stream.good() )
  {
    std::getline( stream, line );
    auto split = splitByDelimiter( line, ' ' );
    if ( split[0] == "noop" )
    {
      elfCPU.commandQueue.push_back( std::make_shared< Noop >() );
    }
    else
    {
      elfCPU.commandQueue.push_back( std::make_shared< AddX >( stoi( split[1] ) ) );
    }
  }
  int signalSum = 0;
  // 20, 60, 100, 140, 180, 220
  for ( int i = 0; i < 240; i++ )
  {
    if ( elfCPU.cycleNum % 40 == 20 )
    {
      signalSum += elfCPU.signalStrength();
    }
    elfCPU.progressCycle();
  }
  std::cout << "\n\nSum of signals: " << signalSum << "\n";
}

} // namespace GDL


// Alternate version here runs the simulation as reads occur, which saves space. 
/*

  std::string line;
  ElfCPU elfCPU;
  int signalSum = 0;
  while ( stream.good() )
  {
    std::getline( stream, line );
    auto split = splitByDelimiter( line, ' ' );
    if ( split[0] == "noop" )
    {
      elfCPU.commandQueue.push_back( std::make_shared< Noop >() );
    }
    else
    {
      elfCPU.commandQueue.push_back( std::make_shared< AddX >( stoi( split[1] ) ) );
    }
    if (elfCPU.cycleNum % 40 == 20)
    {
      signalSum += elfCPU.signalStrength();
    }
    elfCPU.progressCycle();
  }
  for (int i = elfCPU.cycleNum-1; i < 240; i++)
  {
    if (elfCPU.cycleNum % 40 == 20)
    {
      signalSum += elfCPU.signalStrength();
    }
    elfCPU.progressCycle();
  }
*/