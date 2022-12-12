#include "AOCDay11.h"

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

struct OperationMember
{
  virtual long long GetValue(long long currentWorry ) = 0;
};

struct Old : OperationMember
{
  long long GetValue(long long currentWorry ) override
  {
    return currentWorry;
  }
};

struct ConstantNumber : OperationMember
{
  long long value;
  long long GetValue(long long currentWorry ) override
  {
    return value;
  };
  ConstantNumber(long long value )
  {
    this->value = value;
  }
};

struct Monkey
{
  std::vector< long long > items;
  int divisibleTest;
  int trueMonkey, falseMonkey;
  std::shared_ptr< OperationMember > left;
  std::shared_ptr< OperationMember > right;
  bool operationIsMultiply;
  int inspectCount = 0;
};

std::shared_ptr< OperationMember > stringIntoOperationMember( std::string input )
{
  if ( input == "old" ) return std::make_shared< Old >();
  return std::make_shared< ConstantNumber >( std::stoi( input ) );
}

void AOCDay11::processDayInternal( std::istream& stream )
{
  std::string line;
  std::vector< Monkey > monkeys;
  while ( stream.good() )
  {
    Monkey newMonkey;
    std::getline( stream, line ); // Monkey # line
    std::getline( stream, line ); // Items line
    auto split = splitByDelimiter( line, ' ' );
    for ( int i = 2; i < split.size(); i++ )
    {
      auto split2 = splitByDelimiter( split[i], ',' );
      newMonkey.items.push_back( std::stoi( split2[0] ) );
    }
    std::getline( stream, line ); // Operations line
    split = splitByDelimiter( line, ' ' );
    newMonkey.left = stringIntoOperationMember( split[3] );
    newMonkey.operationIsMultiply = split[4] == "*";
    newMonkey.right = stringIntoOperationMember( split[5] );

    std::getline( stream, line ); // Test line
    split = splitByDelimiter( line, ' ' );
    newMonkey.divisibleTest = std::stoi( split[3] );

    std::getline( stream, line ); // True line
    split = splitByDelimiter( line, ' ' );
    newMonkey.trueMonkey = std::stoi( split[5] );
    std::getline( stream, line ); // False line
    split = splitByDelimiter( line, ' ' );
    newMonkey.falseMonkey = std::stoi( split[5] );

    std::getline( stream, line ); // Empty line
    monkeys.push_back( newMonkey );
  }

  long long coolMath = 1;
  for (int i = 0; i < monkeys.size(); i++) {
       coolMath *= monkeys[i].divisibleTest;
  }
  const int roundCount = 20;
  for ( int i = 0; i < roundCount; i++ )
  {
    for ( int monkeyNum = 0; monkeyNum < monkeys.size(); monkeyNum++ )
    {
      auto& currentMonkey = monkeys[monkeyNum];
      std::vector< long long >& items = currentMonkey.items;
      while ( items.size() )
      {
        currentMonkey.inspectCount++;
        long long left = currentMonkey.left->GetValue(items[0]);
        long long right = currentMonkey.right->GetValue(items[0]);
        items[0] = currentMonkey.operationIsMultiply ? left*right : left+right;
        //items[0] %= coolMath;
        items[0] /= 3;
        long long oldItem = items[0];

        if ( items[0] % currentMonkey.divisibleTest == 0 )
        {
          monkeys[currentMonkey.trueMonkey].items.push_back( items[0] );
        }
        else
        {
          monkeys[currentMonkey.falseMonkey].items.push_back( items[0] );
        }
        items.erase( items.begin() );
      }
    }
  }
  int firstMonkey = -1;
  int secondMonkey = -1;
  for ( int i = 0; i < monkeys.size(); i++ )
  {
    if ( monkeys[i].inspectCount > firstMonkey )
    {
      secondMonkey = firstMonkey;
      firstMonkey = monkeys[i].inspectCount;
    }
    else if ( monkeys[i].inspectCount > secondMonkey )
    {
      secondMonkey = monkeys[i].inspectCount;
    }
  }
  std::cout << "Monkey Business: " << firstMonkey * secondMonkey << "\n";
}

} // namespace GDL
