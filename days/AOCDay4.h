#ifndef AOCDAY4_H
#define AOCDAY4_H

#include <AOCDay.h>

namespace GDL
{

class AOCDay4 : public AOCDay
{
  virtual std::filesystem::path inputPath() override
  {
    return "days/input4.txt";
  };

  void processDayInternal(std::istream& stream) override;
};

} // namespace GDL 

#endif