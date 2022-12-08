#ifndef AOCDAY1_H
#define AOCDAY1_H

#include <AOCDay.h>

namespace GDL
{

class AOCDay1 : public AOCDay
{
  virtual std::filesystem::path inputPath() override
  {
    return "days/input1.txt";
  };

  void processDayInternal(std::istream& stream) override;
};

} // namespace GDL 

#endif