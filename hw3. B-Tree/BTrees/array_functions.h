#include <iostream>
#include <cstdlib>

template <class Item>
int first_ge(const Item data[ ], int n, const Item& entry) 
{
    int index;
    index = 0;

    while (index < n)
    {
        if (data[index] >= entry)
            return index;
        index++;
    }
    return index;
}   

template <class Item>
void insert_item(Item data[ ], int index, int& n, Item entry)
{
    assert(index <= n);

    for (int i = n; i > index; i--)
        data[i] = data[i - 1];

    data[index] = entry;
    n++;
}   

template <class Item>
void delete_item(Item data[ ], int index, int& n, Item& entry)
{
    assert(index < n);

    entry = data[index];

    for (int i = index; i < n - 1; i++)
        data[i] = data[i + 1];

    n--;
}   

template <class Item>
void merge(Item data1[ ], int& n1, Item data2[ ], int& n2)
{
    for (int i = n2; i > 0; i--)
        data1[n1++] = data2[n2 - i];

    n2 = 0;
}   

template <class Item>
void split(Item data1[ ], int& n1, Item data2[ ], int& n2)
{
    int mid = n1 / 2;

    if (n1 % 2 != 0)
        for (int i = 0; i < mid; i++)
            data2[i] = data1[mid + 1 + i];
    else
        for (int i = 0; i < mid; i++)
            data2[i] = data1[mid + i];

    n1 = n2 = mid;
}   

template <class Item>
void copy_array(Item dest[], const Item src[],
                int& dest_size, int src_size)
{
    for (int i = 0; i < src_size; i++)
    {
        dest[i] = src[i];
    }
    dest_size = src_size;
}        

template<typename Item>
bool is_sorted(Item* array, int size)
{
    if (size < 2)
        return true;
    else
    {
        for (int i = 1; i < size; i++)
            if (array[i] < array[i - 1])
                return false;
    }

    return true;   
}

