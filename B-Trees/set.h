#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>

template <class Item>
class set
{
  public:
    typedef Item value_type;
    set();
    set(const set& source);
    ~set() {clear();}

    void operator = (const set& source);
    void clear();
    bool insert(const Item& entry);
    std::size_t erase(const Item& target);

    std::size_t count(const Item& target) const;
    bool empty() const {return (data_count == 0);}
  private:
    static const std::size_t MINIMUM =200;
    static const std::size_t MAXIMUM = 2 * MINIMUM;

    std::size_t data_count;
    Item data[MAXIMUM + 1]; 
    std::size_t child_count;
    set *subset[MAXIMUM + 2];

    bool is_leaf() const {return (child_count ==0);}
    bool loose_insert(const Item& entry);
    bool loose_erase(const Item& target);
    void remove_biggest(Item& removed_entry);
    void fix_excess(std::size_t i);
    void fix_shortage(std::size_t i);

    //add other private member
};
//public 
    set();
    set(const set& source);
    ~set() {clear();}

    void operator = (const set& source);
    void clear();
    bool insert(const Item& entry);
    std::size_t erase(const Item& target);

    std::size_t count(const Item& target) const;

 // private
 bool is_leaf() const {return (child_count ==0);}
    bool loose_insert(const Item& entry);
    bool loose_erase(const Item& target);
    void remove_biggest(Item& removed_entry);
    void fix_excess(std::size_t i);
    void fix_shortage(std::size_t i);





//show_contents
template <class Item>
void set<Item> show_contents(int indent) const
{
  const int EXTRA_INDENTATION = 4;
  size_t i;

  //print indentation
  std::cout<< std::setw(indent) << "";
  //print root data 
  for (i = 0; i < data_count; ++i) 
    std::cout << data[i] << " ";
  std::cout << std::endl;
  //print subtrees data
  for (i = 0; i < child_count; ++i) 
    subset[i]->show_contents(indent+EXTRA_INDENTATION);
}