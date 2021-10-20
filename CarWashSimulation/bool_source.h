#include <iostream>
#include <cassert>
#include <cstdlib>

#include <queue>

class bool_source
{
public:
  bool_source(double p =0.5);
  bool query() const;  //외부에서 차 들어왔는지 True/False
private:
   double probability;
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