#include "AOCDay5.h"

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
#include <stack>

namespace GDL
{



void AOCDay5::processDayInternal( std::istream& stream )
{
  std::string line;
  int scorePart1 = 0, scorePart2 = 0;
  std::vector< std::stack<char>> stacks;
  for (int i = 0; i < 9; i++) {
    stacks.push_back( std::stack<char>());
  }
  std::vector< std::string > topLines;

  const auto charIsNumeric = [](char c) {
    return c >= '0' && c <= '9';
  };

  while ( stream.good() )
  {
    std::getline( stream, line );
    if (line[0] == '[') {
      topLines.push_back(line);
    }
    else {
      for (int i = topLines.size() - 1; i >= 0; i--) {
        auto& line = topLines[i];
        int counter = 0;
        for (int j = 1; j < line.size(); j+=4) {
          if (line[j] >= 'A' && line[j] <= 'Z') {
            stacks[counter].push( line[j] );
          }
          counter++;
        }
      }
      break;
    }    
  }
  std::getline(stream, line);
  while (stream.good())
  {
    std::getline(stream, line);
    int moveCount, from, to;
    if (line[6] >= '0' && line[6] <= '9') {
      std::stringstream ss;
      ss << line[5] << line[6];
      std::string s = ss.str();
      moveCount = std::stoi(s);

      from = line[13] - '0';
      to = line[18] - '0';
    }
    else {
      moveCount = line[5] - '0';
      from = line[12] - '0';
      to = line[17] - '0';
    }

    std::vector<char> buffer;
    for (int i = 0; i < moveCount; i++) {
      buffer.push_back(stacks[from - 1].top());
      stacks[from - 1].pop();
    }
    for (int i = moveCount-1; i >= 0; i--) {
      stacks[to - 1].push( buffer[i] );
    }
  }
  std::string part1 = "";
  for (int i = 0; i < 9; i++) {
    part1 += stacks[i].top();
  }
  std::cout << "Part 1:" << part1 << "\n";
  std::cout << "Final score for part 2: " << scorePart2 << "\n";
}

} // namespace GDL
