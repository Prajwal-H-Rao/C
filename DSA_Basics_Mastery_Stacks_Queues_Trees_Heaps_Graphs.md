# DSA Basics Mastery — Stacks, Queues, Trees, Heaps & Graphs

A structured coding-question roadmap for mastering the fundamentals of:

- Stacks
- Queues
- Binary Trees
- Binary Search Trees
- Heaps
- Graphs

The goal is to learn through **implementation → tracing → basic problems → patterns → mixed problems**.

> Recommended for GATE preparation and developer interviews.

---

# 1. Stack — 10 Problems

## A. Implementation

- [ ] 1. Implement stack using an array
- [ ] 2. Implement stack using a linked list
- [ ] 3. Implement `push()`, `pop()`, `peek()`, `isEmpty()`
- [ ] 4. Handle stack overflow and underflow

## B. Basic Problems

- [ ] 5. Reverse a string using a stack
- [ ] 6. Check balanced parentheses
  - `()[]{}` → valid
  - `([)]` → invalid
- [ ] 7. Convert infix expression → postfix
- [ ] 8. Evaluate a postfix expression
- [ ] 9. Implement two stacks in one array
- [ ] 10. Implement a queue using two stacks

## Stack Mastery Checkpoint

Be able to trace:

```text
push(10)
push(20)
push(30)
pop()
peek()
```

Expected structure:

```text
TOP
 ↓
┌────┐
│ 30 │
├────┤
│ 20 │
├────┤
│ 10 │
└────┘
```

Know:

```text
push() → O(1)
pop()  → O(1)
peek() → O(1)
```

---

# 2. Queue — 10 Problems

## A. Implementation

- [ ] 1. Implement queue using an array
- [ ] 2. Implement queue using a linked list
- [ ] 3. Implement `enqueue()`, `dequeue()`, `front()`
- [ ] 4. Implement a circular queue

Understand:

```text
front                    rear
 ↓                         ↓
[10][20][30][40][50]
```

Understand why a circular queue solves the wasted-space problem of a simple array queue.

## B. Problems

- [ ] 5. Implement circular queue
- [ ] 6. Implement queue using two stacks
- [ ] 7. Implement stack using two queues
- [ ] 8. Reverse a queue
- [ ] 9. Generate binary numbers from `1 → N` using a queue
- [ ] 10. Find the first non-repeating character in a stream

Example:

```text
Input:  a a b c
Output: a # b b
```

## Important Concepts

Know the difference between:

```text
Simple Queue
Circular Queue
Deque
Priority Queue
```

---

# 3. Binary Trees — 20 Problems

Trees deserve significant practice time.

## A. Binary Tree Implementation & Traversal

Given:

```text
        1
       / \
      2   3
     / \
    4   5
```

Implement:

- [ ] 1. Create a binary tree
- [ ] 2. Recursive preorder traversal
- [ ] 3. Recursive inorder traversal
- [ ] 4. Recursive postorder traversal
- [ ] 5. Level-order traversal

Remember:

```text
Preorder   = Root Left Right
             1 2 4 5 3

Inorder    = Left Root Right
             4 2 5 1 3

Postorder  = Left Right Root
             4 5 2 3 1

Level order = BFS
              1 2 3 4 5
```

## B. Basic Tree Problems

- [ ] 6. Count total nodes
- [ ] 7. Count leaf nodes
- [ ] 8. Find height of a tree
- [ ] 9. Find depth of a node
- [ ] 10. Find maximum value
- [ ] 11. Find minimum value
- [ ] 12. Search for a value
- [ ] 13. Find sum of all nodes
- [ ] 14. Count nodes at level `K`
- [ ] 15. Check whether two trees are identical

## C. Important Interview Problems

- [ ] 16. Find diameter of a binary tree
- [ ] 17. Check whether a binary tree is balanced
- [ ] 18. Find Lowest Common Ancestor (LCA)
- [ ] 19. Find left view of a binary tree
- [ ] 20. Find right view of a binary tree

---

# 4. Binary Search Trees — 15 Problems

Given:

```text
          50
        /    \
      30      70
     /  \    /  \
   20   40  60   80
```

Practice:

- [ ] 1. Insert into BST
- [ ] 2. Search in BST
- [ ] 3. Find minimum
- [ ] 4. Find maximum
- [ ] 5. Find inorder successor
- [ ] 6. Find inorder predecessor
- [ ] 7. Delete a leaf node
- [ ] 8. Delete a node with one child
- [ ] 9. Delete a node with two children
- [ ] 10. Validate whether a tree is a BST
- [ ] 11. Find kth smallest element
- [ ] 12. Find kth largest element
- [ ] 13. Find LCA in a BST
- [ ] 14. Convert sorted array → balanced BST
- [ ] 15. Find floor and ceil of a value

## Critical BST Concept

Why can BST search be:

```text
O(log n)
```

for a balanced tree:

```text
        50
       /  \
     30    70
```

but:

```text
O(n)
```

for a skewed tree:

```text
10
  \
   20
     \
      30
        \
         40
```

---

# 5. Heap — 15 Problems

First implement both a **min heap** and a **max heap** from scratch.

## A. Heap Implementation

- [ ] 1. Insert into a min heap
- [ ] 2. Insert into a max heap
- [ ] 3. Implement heapify-up
- [ ] 4. Delete root
- [ ] 5. Implement heapify-down
- [ ] 6. Build heap from an array
- [ ] 7. Implement heap sort

For a **0-indexed array**, remember:

```text
parent(i) = (i - 1) / 2

left(i)   = 2i + 1

right(i)  = 2i + 2
```

Example:

```text
        10
       /  \
     20    30
    / \
   40  50
```

Array representation:

```text
[10, 20, 30, 40, 50]
```

## B. Heap Problems

- [ ] 8. Find kth largest element
- [ ] 9. Find kth smallest element
- [ ] 10. Find top K largest elements
- [ ] 11. Find top K smallest elements
- [ ] 12. Merge K sorted arrays
- [ ] 13. Merge K sorted linked lists
- [ ] 14. Find median from a stream
- [ ] 15. Sort a nearly sorted array

## Important Heap Pattern

For **kth largest**:

```text
Use a min heap of size K
```

For **kth smallest**:

```text
Use a max heap of size K
```

---

# 6. Graphs — 25 Problems

Graphs should be your largest practice section.

## A. Graph Representation

Implement:

- [ ] 1. Adjacency matrix
- [ ] 2. Adjacency list
- [ ] 3. Directed graph
- [ ] 4. Undirected graph
- [ ] 5. Weighted graph

Example:

```text
0 ─── 1
│     │
│     │
2 ─── 3
```

Adjacency list:

```text
0 → 1, 2
1 → 0, 3
2 → 0, 3
3 → 1, 2
```

---

# 7. BFS / DFS

## DFS

- [ ] 6. Implement recursive DFS
- [ ] 7. Implement iterative DFS using a stack
- [ ] 8. DFS traversal of a graph

## BFS

- [ ] 9. Implement BFS using a queue
- [ ] 10. Find shortest path in an unweighted graph

Core relationship:

```text
DFS → Stack / Recursion

BFS → Queue
```

---

# 8. Graph Fundamentals

- [ ] 11. Detect cycle in an undirected graph
- [ ] 12. Detect cycle in a directed graph
- [ ] 13. Check whether a graph is connected
- [ ] 14. Count connected components
- [ ] 15. Check whether a graph is bipartite
- [ ] 16. Find a path between two vertices
- [ ] 17. Find all paths between two vertices
- [ ] 18. Topological sort using DFS
- [ ] 19. Topological sort using Kahn's algorithm
- [ ] 20. Detect cycle using topological sorting

---

# 9. Graph Algorithms

## Dijkstra

- [ ] 21. Implement single-source shortest path using Dijkstra

Example:

```text
A --4-- B
|       |
2       1
|       |
C --3-- D
```

Core idea:

```text
Graph
  ↓
Priority Queue
  ↓
Relaxation
  ↓
Shortest distances
```

Understand when Dijkstra **does not work**, especially with negative edge weights.

## Minimum Spanning Tree

- [ ] 22. Prim's algorithm
- [ ] 23. Kruskal's algorithm
- [ ] 24. Disjoint Set Union / Union-Find

## Other Shortest Path Algorithm

- [ ] 25. Bellman-Ford

---

# 10. Recommended Learning Order

Do not randomly solve these problems.

Follow this progression:

```text
STACK
  ↓
QUEUE
  ↓
BINARY TREE
  ↓
BST
  ↓
HEAP
  ↓
GRAPH REPRESENTATION
  ↓
DFS
  ↓
BFS
  ↓
CYCLE DETECTION
  ↓
TOPOLOGICAL SORT
  ↓
DIJKSTRA
  ↓
MST
```

---

# 11. How to Practice Every Problem

For every problem, follow these five steps.

## Step 1 — Draw

Example:

```text
        10
       /  \
      5    20
```

## Step 2 — Explain the Algorithm

Before coding, explain the algorithm verbally.

For example:

> I need to visit the left subtree, then the right subtree.

## Step 3 — Write Pseudocode

Example:

```text
function inorder(node):
    if node == NULL:
        return

    inorder(node.left)
    print(node)
    inorder(node.right)
```

## Step 4 — Code It

For GATE preparation, preferably implement the data structures and core algorithms in **C**.

## Step 5 — Analyze Complexity

Always write:

```text
Time:  O(?)
Space: O(?)
```

---

# 12. Complete Practice Sequence

Since arrays and linked lists are already comfortable, start directly with stacks.

## Stack

- [ ] Q1. Implement a stack using an array
- [ ] Q2. Implement a stack using a linked list
- [ ] Q3. Check whether brackets are balanced
- [ ] Q4. Implement a queue using two stacks
- [ ] Q5. Implement a circular queue

## Trees

- [ ] Q6. Implement a binary tree
- [ ] Q7. Preorder traversal
- [ ] Q8. Inorder traversal
- [ ] Q9. Postorder traversal
- [ ] Q10. Level-order traversal
- [ ] Q11. Find height
- [ ] Q12. Count leaf nodes
- [ ] Q13. Count total nodes
- [ ] Q14. Search for a value
- [ ] Q15. Find diameter

## BST

- [ ] Q16. Insert
- [ ] Q17. Search
- [ ] Q18. Delete
- [ ] Q19. Validate BST
- [ ] Q20. Find kth smallest

## Heaps

- [ ] Q21. Min heap insertion
- [ ] Q22. Max heap insertion
- [ ] Q23. Delete root
- [ ] Q24. Build heap
- [ ] Q25. Heap sort
- [ ] Q26. Find kth largest

## Graphs

- [ ] Q27. Implement adjacency list
- [ ] Q28. DFS
- [ ] Q29. BFS
- [ ] Q30. Connected components
- [ ] Q31. Cycle detection
- [ ] Q32. Bipartite graph
- [ ] Q33. Topological sort
- [ ] Q34. Dijkstra
- [ ] Q35. Prim
- [ ] Q36. Kruskal

---

# 13. Suggested Interactive Practice Method

Instead of looking at all solutions immediately:

1. Read the problem.
2. Try to solve it yourself.
3. Write pseudocode.
4. Implement it.
5. Test edge cases.
6. Analyze time and space complexity.
7. Review the solution.
8. Try a variation of the problem.

For each question, practice:

```text
Problem
   ↓
Understand
   ↓
Draw / Trace
   ↓
Pseudocode
   ↓
Code
   ↓
Test
   ↓
Complexity
   ↓
Variation
```

This turns the list into a structured DSA course rather than just a collection of questions.

---

# 14. Mastery Checklist

Before moving to the next data structure, make sure you can implement the current one **without looking at notes**.

## Stack

- [ ] Array implementation
- [ ] Linked-list implementation
- [ ] Push / pop / peek
- [ ] Overflow / underflow
- [ ] Balanced parentheses
- [ ] Infix → postfix
- [ ] Postfix evaluation
- [ ] Two stacks in one array
- [ ] Queue using stacks

## Queue

- [ ] Array implementation
- [ ] Linked-list implementation
- [ ] Circular queue
- [ ] Queue using stacks
- [ ] Stack using queues
- [ ] Deque concepts
- [ ] Priority queue concepts

## Trees

- [ ] Binary tree construction
- [ ] Preorder
- [ ] Inorder
- [ ] Postorder
- [ ] Level order
- [ ] Height
- [ ] Nodes / leaves
- [ ] Diameter
- [ ] Balanced tree
- [ ] LCA
- [ ] Tree views

## BST

- [ ] Insert
- [ ] Search
- [ ] Delete
- [ ] Min / max
- [ ] Successor / predecessor
- [ ] Validate BST
- [ ] Kth smallest / largest
- [ ] LCA
- [ ] Floor / ceil

## Heap

- [ ] Min heap
- [ ] Max heap
- [ ] Insert
- [ ] Delete
- [ ] Heapify up
- [ ] Heapify down
- [ ] Build heap
- [ ] Heap sort
- [ ] Kth largest / smallest
- [ ] Top K pattern

## Graphs

- [ ] Adjacency matrix
- [ ] Adjacency list
- [ ] Directed graph
- [ ] Undirected graph
- [ ] Weighted graph
- [ ] DFS
- [ ] BFS
- [ ] Connected components
- [ ] Cycle detection
- [ ] Bipartite graph
- [ ] Topological sort
- [ ] Dijkstra
- [ ] Bellman-Ford
- [ ] Prim
- [ ] Kruskal
- [ ] Union-Find

---

# 15. Final Target

By the end of this roadmap, you should be able to look at a problem and identify the underlying pattern:

```text
LIFO problem
    → Stack

FIFO problem
    → Queue

Hierarchical data
    → Tree

Ordered hierarchical search
    → BST

Repeated min/max extraction
    → Heap / Priority Queue

Explore neighbors level-by-level
    → BFS

Explore deeply
    → DFS

Shortest path + non-negative weights
    → Dijkstra

Dependency ordering
    → Topological Sort

Minimum-cost connection
    → MST

Cycle / component connectivity
    → DFS/BFS / Union-Find
```

The objective is not merely to memorize implementations. The objective is to develop the ability to recognize **which data structure or algorithm a problem is asking for**.
