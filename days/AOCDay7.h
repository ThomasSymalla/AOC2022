#ifndef AOCDAY7_H
#define AOCDAY7_H

#include <AOCDay.h>

namespace GDL
{

class AOCDay7 : public AOCDay
{
  virtual std::filesystem::path inputPath() override
  {
    return "days/input7.txt";
  };

  void processDayInternal(std::istream& stream) override;
};

} // namespace GDL 

#endif