#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstdlib>
#include <string>

#include "array_functions.h"

template <class Item>
class set
{
public:
    // CONSTRUCTORS
    set(bool dups = false);
    set(const set<Item>& source);
    // DESTRUCTOR
    ~set();

    set<Item>& operator =(const set<Item>& source);
    void clear();    
    void insert(const Item& entry);              
    bool erase(const Item& entry);             
                        
    void copy_tree(const set<Item>& other);     

    bool contains(const Item& target) const;             
    Item& count(const Item& target);                     
    Item* find(const Item& target);                
    int size() const;                       
    bool empty() const { return data_count == 0; }                        
    void show_contents(int indent = 0, std::ostream &outs = std::cout) const;
    bool is_valid(); 
    friend std::ostream& operator<<(std::ostream& outs, const set<Item>& print)
    {
        print.show_contents(0, outs);
        return outs;
    }
private:
    static const int MINIMUM = 1;
    static const int MAXIMUM = 2 * MINIMUM;

    bool dups_ok;                                   
    int data_count;                               
    Item data[MAXIMUM + 1];                         
    int child_count;                               
    set* subset[MAXIMUM + 2];                    

    bool is_leaf() const { return child_count == 0; }   
    void loose_insert(const Item& entry);             
    void fix_excess(int i);                        
    bool loose_erase(const Item& entry);             
    void fix_shortage(int i);                      
    void remove_biggest(Item& removed_entry);                
    void rotate_left(int index);                       
    void rotate_right(int index);                      
    void merge_with_next_subset(int index);             
};

template<class Item>
set<Item>::set(bool dupes)
{
    data_count = 0;
    child_count = 0;
    dups_ok = dupes;
}

template<class Item>
set<Item>::set(const set<Item>& source)
{
    this->dups_ok = source.dups_ok;
    data_count = 0;
    child_count = 0;
    
    this->copy_tree(source);
}

template<class Item>
set<Item>::~set()
{
    this->clear();
}

template<class Item>
set<Item>& set<Item>::operator=(const set<Item>& source)
{
    this->clear();
    this->copy_tree(source);
    return *this;
}

template<class Item>
void set<Item>::insert(const Item& entry)
{
    loose_insert(entry);

    if (data_count > MAXIMUM)
    {
        set<Item>* new_child;
        new_child = new set<Item>(dups_ok);

        copy_array(new_child->data, data, new_child->data_count, data_count);
        copy_array(new_child->subset, subset, new_child->child_count, child_count);

        data_count = 0;
        child_count = 1;

        subset[0] = new_child;

        fix_excess(0);
    }
}

template<class Item>
bool set<Item>::erase(const Item& entry)
{
    if (!loose_erase(entry))
        return false;
    if (data_count == 0 && child_count == 1)
    {
        set<Item>* temp;
        temp = this->subset[0];

        copy_array(this->data,
                   temp->data,
                   this->data_count,
                   temp->data_count);

        copy_array(this->subset,
                   temp->subset,
                   this->child_count,
                   temp->child_count);

        for (int i = 0; i < temp->child_count; i++)
            temp->subset[i] = NULL;

        temp->child_count = temp->data_count = 0;

        delete temp;        
    }
    return true;
}

template<class Item>
void set<Item>::clear()
{
    for (int i = 0; i < child_count; i++)
    {
        subset[i]->clear();
        delete subset[i];
    }
    for (int i = 0; i < MAXIMUM + 2; i++)
        subset[i] = NULL;
    data_count = child_count = 0;
}


template<class Item>
void set<Item>::copy_tree(const set<Item>& other)
{
    this->clear();
    copy_array(this->data, other.data, this->data_count, other.data_count);
    this->child_count = other.child_count;
    for (int i = 0; i < other.child_count; i++)
    {
        subset[i] = new set(dups_ok);
        subset[i]->copy_tree(*other.subset[i]);
    }
}

template<class Item>
bool set<Item>::contains(const Item& target) const
{
    int index;
    index = first_ge(data, data_count, target);
    if (data[index] == target)
        return true;
    else if (!is_leaf())
        return subset[index]->contains(target);
    else
        return false;
}

template<class Item>
Item* set<Item>::find(const Item& target)
{
    assert(this->contains(target));
    Item* ptr;
    ptr = &this->count(target);
    return ptr;
}

template<class Item>
int set<Item>::size() const
{
    int size;
    size = data_count;
    for (int i = 0; i < child_count; i++)
        size += subset[i]->size();
    return size;
}

template<class Item>
Item& set<Item>::count(const Item& target)
{
    int index;
    index = first_ge(data, data_count, target);
    if (data[index] == target)
        return data[index];
    else if (!is_leaf())
        return subset[index]->count(target);
    else
        std::cout << "Item is not in tree." << std::endl;
}

template<class Item>
void set<Item>::show_contents(int indent, std::ostream& outs) const
{
    if (!is_leaf())
    {
        for (int i = 1; i <= data_count; i++)
        {
            subset[child_count - i]->show_contents(indent + 1, outs);
            outs << std::setw(indent * 4) << "" << data[data_count - i] << std::endl;
        }
            subset[0]->show_contents(indent + 1, outs);
    }
    else
    {
        for (int i = data_count - 1; i >= 0; i--)
            outs << std::setw(indent * 4) << "" << data[i] << std::endl;
    }
}

template<class Item>
bool set<Item>::loose_erase(const Item& target)
{
    Item hold;
    int index;
    bool found;
    index = first_ge(data, data_count, target);

    if (child_count == 0 && data[index] != target || 
        child_count == 0 && index >= data_count)
    {
        return false;
    }
    else if (child_count == 0 && data[index] == target)
    {
        delete_item(data, index, data_count, hold);
        return true;
    }
    else if(child_count > 0 && data[index] != target)
    {
        found = subset[index]->loose_erase(target);
        
        if (subset[index]->data_count < MINIMUM)
            fix_shortage(index);
        
        return found;
    }
    else if(child_count > 0 && data[index] == target)
    {
        subset[index]->remove_biggest(data[index]);
        if (subset[index]->data_count < MINIMUM)
            fix_shortage(index);
        
        return true;
    }
    else
        std::cout << "Something went wrong in loose_remove()" << std::endl;   
}

template<class Item>
void set<Item>::remove_biggest(Item& removed_entry)
{
    if (child_count == 0)
    {
        removed_entry = data[data_count - 1];
        data_count--;
    }
    else
    {
        subset[child_count - 1]->remove_biggest(removed_entry);
        if (subset[child_count - 1]->data_count < MINIMUM)
            fix_shortage(child_count - 1);
    }
}

template<class Item>
void set<Item>::fix_shortage(int i)
{
    Item hold;
    set* tree_hold;
    if(i - 1 >= 0 && subset[i - 1]->data_count > MINIMUM)
    {
        insert_item(subset[i]->data, 0, 
                    subset[i]->data_count, 
                    data[i - 1]);

        data[i - 1] = subset[i - 1]->data[subset[i - 1]->data_count - 1];
        subset[i - 1]->data_count--;
        if (subset[i - 1]->child_count > 0)
        {
            insert_item(subset[i]->subset, 0, 
                        subset[i]->child_count,
                        subset[i - 1]->subset[subset[i - 1]->child_count - 1]);

            subset[i - 1]->child_count--;
        }
    }
    else if (i + 1 < child_count && subset[i + 1]->data_count > MINIMUM)
    {
        insert_item(subset[i]->data, 
                    subset[i]->data_count,
                    subset[i]->data_count,
                    data[i]);

        data[i] = subset[i + 1]->data[0];
        delete_item(subset[i + 1]->data,
                    0, subset[i + 1]->data_count,
                    hold);
        if (subset[i + 1]->child_count > 0)
        {
            insert_item(subset[i]->subset,
                        subset[i]->child_count,
                        subset[i]->child_count,
                        subset[i + 1]->subset[0]);
            delete_item(subset[i + 1]->subset, 0,
                        subset[i + 1]->child_count,
                        tree_hold);
        }
    }
    else if (i - 1 >= 0 && subset[i - 1]->data_count == MINIMUM)
    {
        delete_item(data, i - 1, data_count, hold);
        subset[i - 1]->data[subset[i - 1]->data_count] = hold;
        subset[i - 1]->data_count++;
        merge(subset[i - 1]->data,
              subset[i - 1]->data_count,
              subset[i]->data,
              subset[i]->data_count);
        merge(subset[i - 1]->subset,
              subset[i - 1]->child_count,
              subset[i]->subset,
              subset[i]->child_count);
        delete_item(subset, i, child_count, tree_hold);
        delete tree_hold;
    }
    else if (i + 1 < child_count && subset[i + 1]->data_count == MINIMUM)
    {
        delete_item(data, i, data_count, hold);
        subset[i]->data[subset[i]->data_count] = hold;
        subset[i]->data_count++;
        merge(subset[i]->data,
              subset[i]->data_count,
              subset[i + 1]->data,
              subset[i + 1]->data_count);
        merge(subset[i]->subset,
              subset[i]->child_count,
              subset[i + 1]->subset,
              subset[i + 1]->child_count);
        delete_item(subset, i + 1, child_count, tree_hold);
        delete tree_hold;
    }
    else
    {
        std::cout << "Something went wrong in fix_shortage()" << std::endl;
    }
}

template<class Item>
void set<Item>::fix_excess(int index)
{
    Item mid;
    mid = subset[index]->data[(MAXIMUM + 1) / 2];
    set<Item>* new_child;
    new_child = new set<Item>(dups_ok);
    split(subset[index]->data,
          subset[index]->data_count, 
          new_child->data, 
          new_child->data_count);
    split(subset[index]->subset,
          subset[index]->child_count,
          new_child->subset,
          new_child->child_count);
    insert_item(subset, index + 1, child_count, new_child);
    insert_item(data, index, data_count, mid);
}

template<class Item>
void set<Item>::loose_insert(const Item& entry)
{
    int i;
    i = first_ge(data, data_count, entry);
    if (data[i] == entry)
        data[i] = entry;      
    else if (this->is_leaf())
        insert_item(data, i, data_count, entry);    
    else
    {
        subset[i]->loose_insert(entry);
        if (subset[i]->data_count > MAXIMUM)
            this->fix_excess(i);
    }
}

template<class Item>
bool set<Item>::is_valid()
{
    bool valid;
    valid = true;
    if(!is_sorted(data, data_count))
        return false;
    if(data_count > MAXIMUM)
        return false;
    if(!this->is_leaf() && child_count < data_count)
        return false;
    if(!this->is_leaf())
    {
        for (int i = 0; i < child_count; i++)
        {
            valid = subset[i]->is_valid();
            if (i < child_count - 1 && subset[i]->data[subset[i]->data_count - 1] > data[i])
                return false;
        }
        if (subset[child_count - 1]->data[0] < data[data_count - 1])
            return false;
    }
    return valid;
}