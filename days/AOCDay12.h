#ifndef AOCDAY12_H
#define AOCDAY12_H

#include <AOCDay.h>

namespace GDL
{

class AOCDay12 : public AOCDay
{
  virtual std::filesystem::path inputPath() override
  {
    return "days/input12.txt";
  };

  void processDayInternal(std::istream& stream) override;
};

} // namespace GDL 

#endif