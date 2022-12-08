#include "AOCDay6.h"

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

bool uniquenessCheck(const std::vector<char>& window) {
  for (int i = 0; i < window.size()-1; i++) {
    for (int j = i+1; j < window.size(); j++) {
      if (window[i] == window[j]) {
        return false;
      }
    }
  }
  return true;
}

void AOCDay6::processDayInternal( std::istream& stream )
{


  int index = 13;
  char next;
  std::vector<char> window;
  for (int i = 0; i < 13; i++) {
    window.push_back(stream.get());
  }
  while ( stream.good() )
  {
    index++;
    window.push_back(stream.get());
    if ( uniquenessCheck( window ) ) {
      std::cout << "Part 1:" << index << "\n";
      break;
    }
    window.erase(window.begin());
  }
}

} // namespace GDL
