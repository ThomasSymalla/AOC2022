#ifndef AOCDAY2_H
#define AOCDAY2_H

#include <AOCDay.h>

namespace GDL
{

class AOCDay2 : public AOCDay
{
  virtual std::filesystem::path inputPath() override
  {
    return "days/input2.txt";
  };

  void processDayInternal(std::istream& stream) override;
};

} // namespace GDL 

#endif