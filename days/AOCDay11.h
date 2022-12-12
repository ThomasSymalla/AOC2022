#ifndef AOCDAY11_H
#define AOCDAY11_H

#include <AOCDay.h>

namespace GDL
{

class AOCDay11 : public AOCDay
{
  virtual std::filesystem::path inputPath() override
  {
    return "days/input11.txt";
  };

  void processDayInternal(std::istream& stream) override;
};

} // namespace GDL 

#endif