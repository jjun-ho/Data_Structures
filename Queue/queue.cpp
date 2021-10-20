#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

template <class Item>
class queue
{
public:
  typedef std::size_t size_type ;
  static const size_type CAPACITY = 30 ; 
  queue( ) ;
  void pop( ) ;
  void push(const Item& entry) ;
  bool empty( ) const { return (count == 0) ; } Item front( ) const ;
  size_type size() const { return count ; }
private:
  Item data[CAPACITY] ;
  size_type first ;
  size_type last ;
  size_type count ;
  size_type next_index(size_type i) const { return (i+1)%CAPACITY ; }
};

template <class Item> 
queue<Item>::queue()
{
  count = 0 ;
  first = 0 ;
  last = CAPACITY - 1; 
}

template <class Item> 
Item queue<Item>::front() const
{
  assert(!empty());
  return data[first];
}

template <class Item> 
void queue<Item>::pop()
{
  assert(!empty());
  first = next_index(first);
  --count;
}

template <class Item> 
void queue<Item>::push(const Item& entry)
{
  assert(size() < CAPACITY);
  last = next_index(last);
  data[last] = entry;
  ++count;
}

int main()
{
  queue<double> doubleQueue;
  doubleQueue.push(3);
  doubleQueue.push(4);
  cout << "size:" << doubleQueue.size() << endl;
  cout << "front: " << doubleQueue.front() << endl;
  doubleQueue.pop();
  cout << "size:" << doubleQueue.size() << endl;
  cout << "front: " << doubleQueue.front() << endl;
}

