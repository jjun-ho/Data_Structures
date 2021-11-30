* Graph
- a nonlinear data structure consisting of nodes and links between nodes.
- unlike trees, graph nodes can be linked in any pattern
- graphs can be empty.

* Graph Traversals
-> Depth-First Search:  //깊이우선
- search proceeds from the start vertex to one of its neighbors, then to one of the neighbor’s neighbors, and so on.
- search has to back up if it cannot proceed further
- could be implemented using a stack or recursively

-> Breadth-First Search: //너비우선
- search proceeds from the start vertex to each of its neighbors
- after processing all neighbors, search proceeds to the neighbors’ neighbors, and so on.
- search ends when all reachable vertices have been processed
- could be implemented using a queue