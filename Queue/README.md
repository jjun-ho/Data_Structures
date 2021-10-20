Queue With Array.

Queue
-A data structure of ordered entries such that entries can be inserted at one end (called the rear) and removed at the other end (called the front)
- First-In First Out (FIFO)

Array Implementation
approach 1. 
first and last will always be incremented as items are added or removed
- Problem: Even though there is a room in the array, one may not add a new item once the last reaches the end //memory 공간 낭비

approach 2. 
As the front item is deleted from the array, all remaining items are moved one position to the left so that the value of first will be always 0.
- Problem: very inefficient

*\approach 3: Circular array approach. 
When the rear index reaches the end of the array, we can simply start reusing the available locations at the front of the array.
- next_index = ( current_index + 1 ) % CAPACITY