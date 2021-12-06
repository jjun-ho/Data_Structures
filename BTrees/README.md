B-Tree를 이용한 set 구현

* B-Trees
- A special kind of tree where each node can hold multiple entries of some type.
- A B-tree can be formulated to store a set of entries.
- Alternatively, a B-tree can be formulated to store a bag of entries.
- Rules:
1. The root may have as few as one entry(even no entries if no children)
  Every other node has at least MININUM entries.
2. The maximum number of entries in a node is twice the value of MININUM. 
3. The entries of each B-tree node are stored in a partially filled array, sorted from the smallest entry (at index 0) to the largest entry (at the final used index).  //오름차순
4. The number of subtrees below a nonleaf node is always one more than the number of entries in the node.  
  //현재 노드 데이터 수: k -> 자식 노드 수: k+1
5. For any nonleaf node:
(a) An entry at index i is greater than all the entries in subtree number i of the node.
(b) An entry at index i is smaller than all the entries in subtree number i+1 of the node.
6. Every leaf in a B-tree has the same depth.

