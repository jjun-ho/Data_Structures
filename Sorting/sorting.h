#include <iostream>
#include <algorithm> //swap
#include <cstdlib> //size_t

//Selection Sort
void selectionSort(int data[ ], size_t n)
{ 
  size_t i, j, index_of_largest ;
  int largest ;
  
  if (n==0) 
    return ;
  for ( i = n-1; i >0 ; --i) 
  {
    largest = data[0] ;
    index_of_largest = 0 ;
    for(j=1; j<=i; ++j)
    {
      if(data[j] > largest)
      {
        largest = data[j];
        index_of_largest = j;
      }
    }
    swap(data[i], data[index_of_largest]) ; 
  }
}


//Insertion Sort 
void insertionSort(int data[ ], size_t n) 
{ 
  size_t i, j;
  int next ;
  if (n==0) 
    return ;
  for(i=1; i <n; ++i) 
  { 
    next = data[i];
    j=i;
    while(j>0 && next < data[j-1])
    { 
      data[j] = data[j-1];
      --j; 
    }
    data[j] = next ; 
  }
}
