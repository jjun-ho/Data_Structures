#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>

#include "dnode.h"

using namespace std;

class bag
{
public:
  typedef size_t size_type;
  typedef dnode::value_type value_type;
  bag();
  bag(const bag &source);
  ~bag();

  bool erase_one(const value_type &target);
  void insert(const value_type &entry);

  void operator+=(const bag &addend);
  void operator=(const bag &source);

  bool operator==(const bag &source);
  bool operator!=(const bag &source);

  void show_contents();
  void sort();

  size_type size() const { return many_nodes; }
  size_type count(const value_type &target) const;
  value_type grab() const;

private:
  dnode *head_ptr;
  size_type many_nodes;
};

bag operator+(const bag &b1, const bag &b2);

//default constructor
bag::bag()
{
  head_ptr = NULL;
  many_nodes = 0;
}

//copy constructor
bag::bag(const bag &source)
{
  dnode *tail_ptr;
  list_copy(source.head_ptr, head_ptr, tail_ptr);
  many_nodes = source.many_nodes;
}

//destructor
bag::~bag()
{
  list_clear(head_ptr);
  many_nodes = 0; //not necessary
}

//erase_one
bool bag::erase_one(const value_type &target)
{
  dnode *target_ptr;
  target_ptr = list_search(head_ptr, target);
  if (target_ptr == NULL)
    return false;
  target_ptr->set_data(head_ptr->data());
  list_head_remove(head_ptr);
  --many_nodes;
  return true;
}

//count
bag::size_type bag::count(const value_type &target) const
{
  size_type answer = 0;
  const dnode *cursor;
  cursor = list_search(head_ptr, target);
  while (cursor != NULL)
  {
    ++answer;
    cursor = cursor->fore();
    cursor = list_search(cursor, target);
  }
  return answer;
}

//grab
bag::value_type bag::grab() const
{
  size_type i;
  const dnode *cursor;

  assert(size() > 0);

  i = (rand() % size()) + 1;
  cursor = list_locate(head_ptr, i);
  return cursor->data();
}

//insert
void bag::insert(const value_type &entry)
{
  if (head_ptr == NULL)
    list_head_insert(head_ptr, entry);
  else
    list_insert(head_ptr, entry);
  ++many_nodes;
}

//=
void bag::operator=(const bag &source)
{
  dnode *tail_ptr;
  if (this == &source) //self-assignment
    return;
  list_clear(head_ptr);
  many_nodes = 0;
  list_copy(source.head_ptr, head_ptr, tail_ptr);
  many_nodes = source.many_nodes;
}

//+=
void bag::operator+=(const bag &addend)
{
  dnode *copy_tail_ptr;
  dnode *copy_head_ptr;
  if (addend.many_nodes > 0)
  {
    list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);
    copy_tail_ptr->set_fore(head_ptr);
    head_ptr->set_back(copy_tail_ptr);
    head_ptr = copy_head_ptr;
    many_nodes += addend.many_nodes;
  }
}

//+
bag operator+(const bag &b1, const bag &b2)
{
  bag answer(b1);
  answer += b2;

  return answer;
}

//==
bool bag::operator==(const bag &source)
{
  return this == &source;
}

//!=
bool bag::operator!=(const bag &source)
{
  return !(this == &source);
}

//show_contents
void bag::show_contents()
{
  for (dnode *dnode = head_ptr; dnode != NULL; dnode = dnode->fore())
    cout << dnode->data() << ' ';
}

//sort
void bag::sort()
{
  dnode *i = head_ptr;
  dnode *j = NULL;
  value_type tmp;
  while (i != NULL)
  {
    j = i->fore();
    while (j != NULL)
    {
      if (i->data() > j->data())
      {
        tmp = i->data();
        i->set_data(j->data());
        j->set_data(tmp);
      }
      j = j->fore();
    }
    i = i->fore();
  }
}
