* Selection Sort
- Method:
For each value i (n-1 down to 1), do the following:
  Find the largest element among data[0] through data[i].
  Swap it with data[i].

* Insertion Sort 
- Method:
For each value i (1 up to n-1), do the following:
  Find an appropriate index j between 0 and i-1 for data[i]
  If an appropriate location is found between 0 and i-1,
  then copy data[i] into that location after shifting each data at index j through i-1 one cell to the right
1. Save a copy of the number to be inserted. 
2. Move up the elements before data[i] until you reach the spot to insert the new number.
3. Insert the new number into the open spot.