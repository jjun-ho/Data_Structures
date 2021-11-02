#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>

#include "dnode.h"

using namespace std;

template <class Item>
class stack
{
  public:
    typedef std::size_t size_type;
    typedef Item value_type;
    // CONSTRUCTOR / DESTRUCTOR
    stack() {top_ptr = NULL;}
    stack(const stack& source);
    ~stack() {list_clear(top_ptr);}
    //FUNCTIONS
    void push(const Item& entry);
    void pop();
    void operator = (const stack& source);
    
    size_type size() const {list_lengh(top_ptr);}
    bool empty() const {return (top_ptr == NULL);}
    Item top() const;
  private:
  node<Item> *top_ptr;
};

template <class Item>
stack<Item>:: stack(const stack<Item>& source)
{
  node<Item> * tail_ptr;
  list_copy(source.top_ptr, top_ptr, tail_ptr);
}

template <class Item>
void stack<Item>:: push(const Item& entry)
{
  list_head_insert(top_ptr, entry);
}

template <class Item>
void stack<Item>::pop()
{
  assert(!empty());
  list_head_remove(top_ptr);
}

template <class Item>
void stack<Item>::operator =(const stack<Item>& source)
{
  node<Item> *tail_ptr;

  if (this == &source)
    return;
  list_clear(top_ptr);
  list_copy(source.top_ptr, top_ptr, tail_ptr);
}

template <class Item>
Item stack<Item>::top() const
{
  assert(!empty());
  return top_ptr -> data();
}