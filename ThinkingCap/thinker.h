#include <iostream>
#include <cassert>

using namespace std;

class ThinkingCap
{
public:
  //ThinkingCap();
  void slots(char new_green[ ], char new_red[ ]); 
  void push_green( ) const {cout<< green_string << endl;};     //will not change
  void push_red( ) const {cout<< red_string << endl;};       //will not change
private:   
  char green_string[50];
  char red_string[50];
};

void ThinkingCap::slots(char new_green[], char new_red[])
{
assert(strlen(new_green)<= 50);
assert(strlen(new_red)<= 50);
strcpy(green_string, new_green);
strcpy(red_string, new_red);
}
