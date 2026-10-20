A binary heap is a complete binary tree.
It is usually represented by an array where the 0th index is the root of the heap.
\
Indices of the other nodes for the ith Node: \
-> Array[0] will be the root element. \
-> The parent Node is given by array[(i-1)/2] \
-> The left child node is given by array[(2*i)+1] \
-> The right child node is given by array[(2*i)+2] \

The traversal used for array representation is level order traversal \

** In a min heap the root is alway the smallest element ** \
** In a max heap the root is always the largest element ** \
\
** On every crud operation on the heap the heap structure is always maintained but extraction of the smallest/ largest element takes constant time ** \

**_ Only the root element can be deleted from a heap _**
