* Serial Search
- searches for a desired item in an array in a serial fashion (from the beginning to the end).
- search stops when the item is found or when the search has examined every item without success.

* Binary Search
- searches for a desired item in a sorted array in a binary fashion.
- search stops when the item is found or when the search has examined every item without success.

* Hashing
- a technique of mapping a key value into an array index.
- uses a hash function to determine the index.
- Hashing can be used for storing and retrieving data.
- Collision could occur when two distinct keys map into the same array index -> Collision resolution is needed.

* Open-Address Hashing Storage Algorithm
1. Given a record with key k, compute the index by a hash function, say hash(key).
2. If data[hash(key)] is empty, then store the record in data[hash(key)] and exit.
3. Otherwise, check to see if data[hash(key)+1] is empty. If so, store the record there. Otherwise, try data[hash(key)+2] and so on.

* The Table Class
- A table is a container of records with operations for inserting, deleting, and locating records.
- Unlike a bag, each table operation is controlled by a single key field.
- A hash table is a table with a hash function.

* Hash Functions
1. Division Hash Functions
- usually computes key % table_size.
2. Mid_Square Hash Functions
- a good table_size is a prime number of form 4k+3 
- takes some middle digits (in binary) of key * key.
3. Multiplicative Hash Functions
- takes the first few digits of a * key (0< a <1).

* Types of Open-Address Hashing
1. Linear Probing
- if location hash(key) is not empty, try hash(key)+1, hash(key)+2, hash(key)+3, and so on in circular fashion until a vacant spot is found.
2. Double Hashing
- In linear probing, when several keys are hashed into the same location, the result is a small cluster of elements.
- The clustering problem makes insertions take longer.
- if location hash(key) is not empty, use a second hash function - double hashing - to determine the step length (how far forward to move through).
- if location hash1(key) is not empty, compute hash2(key). 
- Now hash2(key) is the step length.

* Chained Hashing
- Each array component can hold more than one entry.