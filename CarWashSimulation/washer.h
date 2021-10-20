#include <iostream>
#include <cassert>
#include <cstdlib>

#include <queue>

using namespace std;

class washer
{
public:
  washer(unsigned int s = 60);
  void one_second();
  void start_washing();
  bool is_busy() const {return (wash_time_left > 0);}
private:
  unsigned int seconds_for_wash;
  unsigned int wash_time_left;
};

//Constructor
washer::washer(unsigned int s)
{
  seconds_for_wash = s;
  wash_time_left =0;
}

void washer::one_second() // 외부 -> washer 1초 지났음을 알려줌
{
  if(is_busy())
    --wash_time_left;
}

void washer::start_washing() //wash x -> wash 시작
{
  assert(!is_busy());
  wash_time_left = seconds_for_wash;
}

