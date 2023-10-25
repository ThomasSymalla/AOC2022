#ifndef AOCDAY13_H
#define AOCDAY13_H

#include <AOCDay.h>

namespace GDL
{

class AOCDay13 : public AOCDay
{
  virtual std::filesystem::path inputPath() override
  {
    return "days/input13.txt";
  };

  void processDayInternal(std::istream& stream) override;
};

} // namespace GDL 

#endif