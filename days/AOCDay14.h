#ifndef AOCDAY14_H
#define AOCDAY14_H

#include <AOCDay.h>

namespace GDL
{

class AOCDay14 : public AOCDay
{
  virtual std::filesystem::path inputPath() override
  {
    return "days/input14.txt";
  };

  void processDayInternal(std::istream& stream) override;
};

} // namespace GDL 

#endif