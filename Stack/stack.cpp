//Stack With Array
#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

template <class Item>
class stack
{
public:
  typedef std::size_t size_type;
  typedef Item value_type;
  static const size_type CAPACITY = 30;
  //Constructor
  stack() {used =0;}
  //Member Functions
  void push(const Item& entry);
  void pop();
  Item top() const;
  size_type size() const {return used;}
  bool empty() const {return (used == 0);}

private:
  Item data[CAPACITY];
  size_type used;
};


template <class Item>
const typename stack<Item>::size_type stack<Item>::CAPACITY;

//Push
template <class Item>
void stack<Item>::push(const Item& entry)
{
  assert(size() < CAPACITY);
  data[used] = entry;
  ++used;
}

//Pop
template <class Item>
void stack<Item>::pop()
{
  assert(!empty());
  --used;
}

//Top
template <class Item>
Item stack<Item>::top() const
{
  assert(!empty());
  return data[used-1];
}

int main()
{
  stack<double> doubleStack;

  doubleStack.push(3);
  doubleStack.push(4);
  cout<< "top: "<< doubleStack.top() << endl;
  cout<< "size: " <<doubleStack.size() <<endl;
  doubleStack.pop();
  cout<< "top: "<< doubleStack.top() << endl;
  doubleStack.pop();
  cout<< "empty?(1:True, 2:False): "<< doubleStack.empty() << endl;
}