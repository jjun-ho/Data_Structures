#include <iostream>
#include <cstdlib>

#include "thinker.h"

using namespace std;

int main()
{
  ThinkingCap student;
  ThinkingCap fan;

  student.slots("Hello", "Goodbye");
  fan.slots("Goo", "Boo");
  student.push_green();
  fan.push_green();
  student.push_red();
}
  
  