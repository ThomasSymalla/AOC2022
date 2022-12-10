#ifndef AOCDAY8_H
#define AOCDAY8_H

#include <AOCDay.h>

namespace GDL
{

class AOCDay8 : public AOCDay
{
  virtual std::filesystem::path inputPath() override
  {
    return "days/input8.txt";
  };

  void processDayInternal(std::istream& stream) override;
};

} // namespace GDL 

#endif