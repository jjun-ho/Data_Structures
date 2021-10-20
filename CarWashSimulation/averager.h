#include <iostream>
#include <cassert>
#include <cstdlib>

#include <queue>

class averager
{
public:
  averager();
  void next_number(double value);
  std::size_t how_many_numbers() const {return count;}
  double average() const;
private:
  std::size_t count;  //몇개의 차 service
  double sum;         //걸린 시간 + 대기한 시간
};

averager::averager()
{
  count = 0;
  sum = 0;
}

void averager::next_number(double value) //차 service 될 때까지 기다렸던 시간: 대기 시간
{
  ++count;
  sum += value;
}

double averager::average() const
{
  assert(how_many_numbers() > 0);
  return sum/count;
}