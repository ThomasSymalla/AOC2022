#include "AOCDay.h"

#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <sstream>
#include <thread>

namespace GDL
{

std::unique_ptr< std::istream > AOCDay::getInput()
{
  std::unique_ptr< std::ifstream > file = std::make_unique< std::ifstream >();
  file->open( std::filesystem::current_path() / inputPath() );
  return file;
}

void AOCDay::processDay( const int& runs )
{
  if ( runs == 1 )
  {
    std::cout << "Calling processDay().\n";
    auto startTime = std::chrono::high_resolution_clock::now();
    processDayInternal( *getInput() );
    auto endTime = std::chrono::high_resolution_clock::now();
    auto durationMicro = std::chrono::duration_cast< std::chrono::microseconds >( endTime - startTime );
    auto durationMilli = std::chrono::duration_cast< std::chrono::milliseconds >( endTime - startTime );
    std::cout << "Finished. Time taken by function: " << durationMicro.count() << char( 230 ) << "s ("
              << durationMilli.count() << "ms).\n";
  }
  else if ( runs > 1 )
  {
    long long sum = 0;
    auto input = getInput();
    for ( int i : std::views::iota( 1, runs ) )
    {
      std::cout << "Calling processDay().\n";
      auto startTime = std::chrono::high_resolution_clock::now();
      processDayInternal( *input );
      auto endTime = std::chrono::high_resolution_clock::now();
      auto durationMicro = std::chrono::duration_cast< std::chrono::microseconds >( endTime - startTime );
      auto durationMilli = std::chrono::duration_cast< std::chrono::milliseconds >( endTime - startTime );
      sum += durationMicro.count();
      std::cout << "Finished. Time taken by function: " << durationMicro.count() << char( 230 ) << "s ("
                << durationMilli.count() << "ms).\n";
      input->clear();
      input->seekg( 0, std::ios::beg );
    }
    int micro = sum / runs;
    int milli = micro / 1000;
    std::cout << "Total average runtime: " << micro << char( 230 ) << "s (" << milli << "ms).\n";
  }
  else
  {
    std::cout << "Provided invalid run count for processDay(): " << runs << "\n";
  }
}

} // namespace GDL