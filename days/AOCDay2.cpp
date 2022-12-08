#include "AOCDay2.h"

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

/*
For this problem, we represent Rock, Paper, and Scissors as ints 0, 1, and 2.
This way we can use the following expression to determine a win:
int result = (ours - theirs) % 3
0 is a tie, 1 is a win, 2 is a loss.
*/


void AOCDay2::processDayInternal( std::istream& stream )
{
  std::string line;
  int scorePart1 = 0, scorePart2 = 0;
  while (stream.good())
  {
    std::getline(stream, line);
    auto result = splitByDelimiter(line, ' ');
    int theirs = (result[0])[0] - 'A';
    int ours;
    // Processing for Part A.
    ours = (result[1])[0] - 'X';
    scorePart1 += 3 * ((((ours - theirs) % 3)+1) % 3);
    scorePart1 += ours + 1;
    // Processing for Part B.

    scorePart2 += ours;
  }
  std::cout << "Final score for part 1: " << scorePart1 << "\n";
  std::cout << "Final score for part 2: " << scorePart2 << "\n";
}

} // namespace GDL