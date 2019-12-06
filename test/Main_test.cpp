#include <iostream>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
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

using namespace std;
int main(int argc,char* argv[])
{ 
    std::cout << "Hello Test!" << std::endl;
    timezonetest();
    //testing::GTEST_FLAG(output) = "xml:"; //生成xml结果文件
    testing::InitGoogleTest(&argc,argv); //初始化
    if( RUN_ALL_TESTS())  //跑单元测试
	        return 0;
}