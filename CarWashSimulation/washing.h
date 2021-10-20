#include <iostream>
#include <cassert>
#include <cstdlib>

class bool_source
{
public:
  bool_source(double p =0.5);
  bool query() const;  //외부에서 차 들어왔는지 True/False
private:
   double probability;
};

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
bool_source::bool_source(double p)
{
  assert(p >= 0);
  assert(p <= 1);
  probability = p;
}

bool bool_source::query() const //차 있는지 True/False
{
  return(rand() < probability* RAND_MAX);
}


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

