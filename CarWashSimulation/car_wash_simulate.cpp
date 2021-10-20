#include <iostream>
#include <cassert>
#include <cstdlib>

#include <queue>

#include "washing.h"

using namespace std;

void car_wash_simulate(unsigned int wash_time, double arrival_prob, unsigned int total_time)
{
  queue<unsigned int> arrival_times;
  unsigned int next;
  bool_source arrival(arrival_prob);
  washer machine(wash_time);
  averager wash_times;
  unsigned int current_second;
  for (current_second=1; current_second <= total_time; ++current_second)
  {
    if (arrival.query())
      arrival_times.push(current_second) ;
    if (!machine.is_busy()) && (!arrival_times.empty())) 
    {
      next = arrival_times.front() ;
      arrival_times.pop( ) ;
      wait_times.next_number(current_second – next) ;
      machine.start_washing( ) ; 
    }
    machine.one_second() ;
  } 
  cout << averager() << endl;
}
