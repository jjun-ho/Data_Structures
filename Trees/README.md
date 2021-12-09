* Trees
- A tree is a nonlinear structure.

* Binary Trees
- Each node can have up to two children, its left child and right child.  //최대 자식 2개
- The left subtree of a node is its subtree whose root is its left child.
- The right subtree of a node is its subtree whose root is its right child.

* Full Binary Trees
- Every leaf has the same depth.
- Every nonleaf node has two children.  //자식 있으면, 무조건 2개

* Complete Binary Trees
- Every level(depth) except the deepest must contain as many nodes as possible. (At depth k (< the deepest level), there must be 2^k nodes).
- At the deepest level, all the nodes are as far left as possible.

* Binary Tree Nodes
- Representing a Binary Tree with a Class for Nodes.
- Tree Traversals: pre-order, in-order , post-order.

* Binary Search Trees
- A binary tree with the following properties:
1. Any data entry in the left subtree 17 of a given node N is less than or equal to the data in node N.
2. Any data entry in the right subtree of a given node N is larger than the data in node N.

* Heaps
- A heap is a complete binary tree with the following property:
1. For any node n in the tree, the data of n is never less than the data of its children.
2. To add an entry to a heap, place the new entry at the next available spot, and perform a reheapification upward.
3. To remove the biggest entry, move the last node onto the root, and perform a reheapification downward.