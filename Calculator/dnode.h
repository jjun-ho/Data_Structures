#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>

using namespace std;

template <class Item>
class dnode
{
public:
  typedef Item value_type;
  // CONSTRUCTOR
  dnode<Item>(const value_type &init_data = value_type(), dnode<Item> *init_fore = NULL, dnode<Item> *init_back = NULL)
  {
    data_field = init_data;
    link_fore = init_fore;
    link_back = init_back;
  }

  void set_data(const value_type &new_data) { data_field = new_data; }
  void set_fore(dnode<Item> *new_fore) { link_fore = new_fore; }
  void set_back(dnode<Item> *new_back) { link_back = new_back; }

  Item& data() const { return data_field; }

  const dnode<Item> *fore() const { return link_fore; }
  dnode<Item> *fore() { return link_fore; }
  const dnode<Item> *back() const { return link_back; }
  dnode<Item> *back() { return link_back; }

private:
  Item data_field;
  dnode<Item> *link_fore;
  dnode<Item> *link_back;
};

// FUNCTIONS for the linked-list toolkit
template <class Item>
size_t list_length(const dnode<Item> *head_ptr);
template <class Item>
void list_head_insert(dnode<Item> *&head_ptr, const Item &entry);
template <class Item>
void list_insert(dnode<Item> *previous_ptr, const Item &entry);
template <class Item>
dnode<Item> *list_search(dnode<Item> *head_ptr, const Item &target);
template <class Item>
const dnode<Item> *list_search(const dnode<Item> *head_ptr, const Item &target);
template <class Item>
dnode<Item> *list_locate(dnode<Item> *head_ptr, size_t position);
template <class Item>
const dnode<Item> *list_locate(const dnode<Item> *head_ptr, size_t position);
template <class Item>
void list_copy(const dnode<Item> *source_ptr, dnode<Item> *&head_ptr, dnode<Item> *&tail_ptr);
template <class Item>
void list_head_remove(dnode<Item> *&head_ptr);
template <class Item>
void list_remove(dnode<Item> *previous_ptr);
template <class Item>
void list_clear(dnode<Item> *&head_ptr);

//dnode<Item> *head_ptr;
//dnode<Item> *tail_ptr;

//list_lengh
template <class Item>
size_t list_lengh(const dnode<Item> *head_ptr)
{
  size_t answer = 0;
  const dnode<Item> *cursor;
  for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore())
    ++answer;
  return answer;
}

//list_head_insert
template <class Item>
void list_head_insert(dnode<Item> *&head_ptr, const Item &entry)
{
  dnode<Item> *new_ptr = new dnode(entry, head_ptr);
  if (head_ptr != NULL)
    head_ptr->set_back(new_ptr);
  head_ptr = new_ptr;
}

//list_insert
template <class Item>
void list_insert(dnode<Item> *previous_ptr, const Item &entry)
{
  dnode<Item> *insert_ptr;

  insert_ptr = new dnode(entry, previous_ptr->fore(), previous_ptr);
  if (previous_ptr->fore() != NULL)
    previous_ptr->fore()->set_back(insert_ptr);
  previous_ptr->set_fore(insert_ptr);
}

//list_search(2 version)
template <class Item>
dnode<Item> *list_search(dnode<Item> *head_ptr, const Item &target)
{
  dnode<Item> *cursor;
  for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore())
    if (target == cursor->data())
      return cursor;
  return NULL;
}
template <class Item>
const dnode<Item> *list_search(const dnode<Item> *head_ptr, const Item &target)
{
  const dnode<Item> *cursor;
  for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore())
    if (target == cursor->data())
      return cursor;
  return NULL;
}

//list_locate(2 version)
template <class Item>
dnode<Item>*list_locate(dnode<Item> *head_ptr, size_t position) // position > 0
{
  dnode<Item> *cursor = head_ptr;
  size_t i;
  assert(0 < position);
  for (i = 1; (cursor != NULL && i < position); ++i)
    cursor = cursor->fore();
  return cursor;
}
template <class Item>
const dnode<Item> *list_locate(const dnode<Item> *head_ptr, size_t position) // position>0
{
  const dnode<Item> *cursor = head_ptr;
  size_t i;
  assert(0 < position);
  for (i = 1; (cursor != NULL && i < position); ++i)
    cursor = cursor->fore();
  return cursor;
}

//list_copy
template <class Item>
void list_copy(const dnode<Item> *source_ptr, dnode<Item> *&head_ptr, dnode<Item> *&tail_ptr)
{
  head_ptr = NULL;
  tail_ptr = NULL;
  if (source_ptr == NULL)
    return;
  list_head_insert(head_ptr, source_ptr->data());
  tail_ptr = head_ptr;
  source_ptr = source_ptr->fore();
  while (source_ptr != NULL)
  {
    list_insert(tail_ptr, source_ptr->data());
    tail_ptr = tail_ptr->fore();
    source_ptr = source_ptr->fore();
  }
}

//list_head_remove
template <class Item>
void list_head_remove(dnode<Item> *&head_ptr)
{
  dnode<Item> *remove_ptr;
  remove_ptr = head_ptr;
  head_ptr = head_ptr->fore();
  delete remove_ptr;
}

//list_move
template <class Item>
void list_remove(dnode<Item> *previous_ptr)
{
  dnode<Item> *remove_ptr;
  remove_ptr = previous_ptr->fore();
  previous_ptr->set_fore(remove_ptr->fore());
  if (remove_ptr->fore() != NULL)
    remove_ptr->fore()->set_back(previous_ptr);
  delete remove_ptr;
}

//list_clear
template <class Item>
void list_clear(dnode<Item> *&head_ptr)
{
  while (head_ptr != NULL)
    list_head_remove(head_ptr);
}