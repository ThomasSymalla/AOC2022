#ifndef AOCDAY3_H
#define AOCDAY3_H

#include <AOCDay.h>

namespace GDL
{

class AOCDay3 : public AOCDay
{
  virtual std::filesystem::path inputPath() override
  {
    return "days/input3.txt";
  };

  void processDayInternal(std::istream& stream) override;
};

} // namespace GDL 

#endif