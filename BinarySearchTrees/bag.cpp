#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>

using namespace std;

template <class Item>
class bag
{
  public:
    typedef std::size_t size_type;
    typedef Item value_type;
    
    bag( );
    bag(const bag& source);
    ~bag( );

    size_type erase(const Item& target);
    bool erase_one(const Item& target);
    void insert(const Item& entry);
    void operator +=(const bag& addend);
    void operator =(const bag& source);

    size_type size( ) const;  
    size_type count(const Item& target) const;
  private:
    binary_tree_node<Item> *root_ptr; 
};

