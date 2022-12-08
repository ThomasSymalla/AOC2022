#ifndef AOCDAY6_H
#define AOCDAY6_H

#include <AOCDay.h>

namespace GDL
{

class AOCDay6 : public AOCDay
{
  virtual std::filesystem::path inputPath() override
  {
    return "days/input6.txt";
  };

  void processDayInternal(std::istream& stream) override;
};

} // namespace GDL 

#endif