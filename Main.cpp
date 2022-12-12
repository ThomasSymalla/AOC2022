#include <AOCDay.h>
#include <Helpers.h>
#include <days/AOCDay1.h>
#include <days/AOCDay2.h>
#include <days/AOCDay3.h>
#include <days/AOCDay4.h>
#include <days/AOCDay5.h>
#include <days/AOCDay6.h>
#include <days/AOCDay7.h>
#include <days/AOCDay8.h>
#include <days/AOCDay9.h>
#include <days/AOCDay10.h>
#include <days/AOCDay11.h>
#include <days/AOCDay12.h>

int main()
{
  std::unique_ptr< GDL::AOCDay > day = std::make_unique< GDL::AOCDay12 >();
  day->processDay( 1 );
}
