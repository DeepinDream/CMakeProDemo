#include <iostream>
#include "mod1/mod1.h"
#include "mod1/submod1/submod1.h"
#include "mod2/mod2.h"
#include "timezone/date/tz.h"

void timezonetest()
{
  using namespace std;
  using namespace std::chrono;
  using namespace date;
  auto zt = date::make_zoned(date::current_zone(),
                             std::chrono::system_clock::now());
  auto now = date::floor<std::chrono::minutes>(zt.get_local_time());
  auto dp = date::floor<date::days>(now);
  auto time = date::make_time(now - dp);
  int hours = time.hours().count();
  int minutes = time.minutes().count();
  std::cout.fill('0');
  std::cout << hours << ':' << minutes << '\n';
}

int main()
{
  std::cout << "Hello World!" << std::endl;

  Mod1 mod1;
  mod1.func();

  SubMod1 subMod1;
  subMod1.func();

  Mod2 mod2;
  mod2.func();

  timezonetest();

  return 0;
}