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