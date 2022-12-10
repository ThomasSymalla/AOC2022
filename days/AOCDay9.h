#ifndef AOCDAY9_H
#define AOCDAY9_H

#include <AOCDay.h>

namespace GDL
{

class AOCDay9 : public AOCDay
{
  virtual std::filesystem::path inputPath() override
  {
    return "days/input9.txt";
  };

  void processDayInternal(std::istream& stream) override;
};

} // namespace GDL 

#endif