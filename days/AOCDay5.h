#ifndef AOCDAY5_H
#define AOCDAY5_H

#include <AOCDay.h>

namespace GDL
{

class AOCDay5 : public AOCDay
{
  virtual std::filesystem::path inputPath() override
  {
    return "days/input5.txt";
  };

  void processDayInternal(std::istream& stream) override;
};

} // namespace GDL 

#endif