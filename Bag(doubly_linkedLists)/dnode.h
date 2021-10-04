#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>

using namespace std;

class dnode
{
public:
  typedef double value_type;
  // CONSTRUCTOR
  dnode(const value_type &init_data = value_type(), dnode *init_fore = NULL, dnode *init_back = NULL)
  {
    data_field = init_data;
    link_fore = init_fore;
    link_back = init_back;
  }

  void set_data(const value_type &new_data) { data_field = new_data; }
  void set_fore(dnode *new_fore) { link_fore = new_fore; }
  void set_back(dnode *new_back) { link_back = new_back; }

  value_type data() const { return data_field; }

  const dnode *fore() const { return link_fore; }
  dnode *fore() { return link_fore; }
  const dnode *back() const { return link_back; }
  dnode *back() { return link_back; }

private:
  value_type data_field;
  dnode *link_fore;
  dnode *link_back;
};

// FUNCTIONS for the linked-list toolkit
size_t list_length(const dnode *head_ptr);
void list_head_insert(dnode *&head_ptr, const dnode::value_type &entry);
void list_insert(dnode *previous_ptr, const dnode::value_type &entry);
dnode *list_search(dnode *head_ptr, const dnode::value_type &target);
const dnode *list_search(const dnode *head_ptr, const dnode::value_type &target);
dnode *list_locate(dnode *head_ptr, size_t position);
const dnode *list_locate(const dnode *head_ptr, size_t position);
void list_copy(const dnode *source_ptr, dnode *&head_ptr, dnode *&tail_ptr);
void list_head_remove(dnode *&head_ptr);
void list_remove(dnode *previous_ptr);
void list_clear(dnode *&head_ptr);

dnode *head_ptr;
dnode *tail_ptr;

//list_lengh
size_t list_lengh(const dnode *head_ptr)
{
  size_t answer = 0;
  const dnode *cursor;
  for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore())
    ++answer;
  return answer;
}

//list_head_insert
void list_head_insert(dnode *&head_ptr, const dnode::value_type &entry)
{
  dnode *new_ptr = new dnode(entry, head_ptr);
  if (head_ptr != NULL)
    head_ptr->set_back(new_ptr);
  head_ptr = new_ptr;
}

//list_insert
void list_insert(dnode *previous_ptr, const dnode::value_type &entry)
{
  dnode *insert_ptr;

  insert_ptr = new dnode(entry, previous_ptr->fore(), previous_ptr);
  if (previous_ptr->fore() != NULL)
    previous_ptr->fore()->set_back(insert_ptr);
  previous_ptr->set_fore(insert_ptr);
}

//list_search(2 version)
dnode *list_search(dnode *head_ptr, const dnode::value_type &target)
{
  dnode *cursor;
  for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore())
    if (target == cursor->data())
      return cursor;
  return NULL;
}
const dnode *list_search(const dnode *head_ptr, const dnode::value_type &target)
{
  const dnode *cursor;
  for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore())
    if (target == cursor->data())
      return cursor;
  return NULL;
}

//list_locate(2 version)
dnode *list_locate(dnode *head_ptr, size_t position) // position > 0
{
  dnode *cursor = head_ptr;
  size_t i;
  assert(0 < position);
  for (i = 1; (cursor != NULL && i < position); ++i)
    cursor = cursor->fore();
  return cursor;
}
const dnode *list_locate(const dnode *head_ptr, size_t position) // position>0
{
  const dnode *cursor = head_ptr;
  size_t i;
  assert(0 < position);
  for (i = 1; (cursor != NULL && i < position); ++i)
    cursor = cursor->fore();
  return cursor;
}

//list_copy
void list_copy(const dnode *source_ptr, dnode *&head_ptr, dnode *&tail_ptr)
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
void list_head_remove(dnode *&head_ptr)
{
  dnode *remove_ptr;
  remove_ptr = head_ptr;
  head_ptr = head_ptr->fore();
  delete remove_ptr;
}

//list_move
void list_remove(dnode *previous_ptr)
{
  dnode *remove_ptr;
  remove_ptr = previous_ptr->fore();
  previous_ptr->set_fore(remove_ptr->fore());
  if (remove_ptr->fore() != NULL)
    remove_ptr->fore()->set_back(previous_ptr);
  delete remove_ptr;
}

//list_clear
void list_clear(dnode *&head_ptr)
{
  while (head_ptr != NULL)
    list_head_remove(head_ptr);
}