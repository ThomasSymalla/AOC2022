#ifndef AOCDAY_H
#define AOCDAY_H

#include <filesystem>
#include <iostream>
#include <sstream>
#include <vector>

namespace GDL
{

class AOCDay
{
public:
  virtual std::filesystem::path inputPath() = 0;
  std::unique_ptr< std::istream > getInput();
  void processDay( const int& runs );

private:
  virtual void processDayInternal( std::istream& stream ) = 0;
};

} // namespace GDL
#endif