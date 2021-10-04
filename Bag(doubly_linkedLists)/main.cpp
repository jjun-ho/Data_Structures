#include <iostream>

#include "bag.h"

using namespace std;

int main()
{

  //constructor
  bag b1, b2, b4;

  //show_contents
  cout << "empty bag, b1:";
  b1.show_contents();
  cout << endl;

  //insert
  b1.insert(1);
  b1.insert(2);
  b1.insert(3);
  b1.insert(3);
  b1.insert(4);

  b2.insert(7);
  b2.insert(8);
  b2.insert(9);

  cout << "inserted bag b1: ";
  b1.show_contents();
  cout << endl;

  cout << "inserted bag, b2: ";
  b2.show_contents();
  cout << endl;

  //copy constructor
  bag b3(b1);
  cout << "copied bag, b3: ";
  b3.show_contents();
  cout << endl;

  //sort
  b1.sort();
  cout << "sorted bag, b1: ";
  b1.show_contents();
  cout << endl;

  //grab
  cout << "grab random number in b1: ";
  cout << b1.grab() << endl;

  //count
  cout << "The number of specific number(3) in b1: ";
  cout << b1.count(3);
  cout << endl;

  //erase_one
  b1.erase_one(3);
  cout << "After one number is erased, b1: ";
  b1.show_contents();
  cout << endl;

  //+=
  b1 += b2;
  cout << "b1 += b2, b1: ";
  b1.show_contents();
  cout << endl;

  //+
  cout << "b4 = b1 + b2, b4: ";
  b4 = b1 + b2;
  b4.show_contents();
  cout << endl;

  //==
  cout << "b1, b2 same?: ";
  if (b1 == b2)
    cout << "same!" << endl;
  else
    cout << "difference!" << endl;

  //!=
  cout << "b1, b1 same?: ";
  if (b1 != b1)
    cout << "difference!!" << endl;
  else
    cout << "same!!" << endl;
}