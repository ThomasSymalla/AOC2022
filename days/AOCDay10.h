#ifndef AOCDAY10_H
#define AOCDAY10_H

#include <AOCDay.h>

namespace GDL
{

class AOCDay10 : public AOCDay
{
  virtual std::filesystem::path inputPath() override
  {
    return "days/input10.txt";
  };

  void processDayInternal(std::istream& stream) override;
};

} // namespace GDL 

#endif