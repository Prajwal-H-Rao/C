# C for GATE DSA 2027 — 6-Day / 30 Coding Questions

**Who this is for:** You know Python and C++, so no syntax hand-holding — these are straight "write a program that..." tasks covering the C mechanics every DSA structure depends on: pointers, manual memory management, structs, recursion, strings, and bit tricks.

**Rules for each question (unless stated otherwise):**
- No STL/`<algorithm>`-equivalent shortcuts — you're building the primitives.
- Where a question says "without library functions," don't use `string.h`/`stdlib.h` helpers for that specific operation.
- Compile with `gcc -Wall file.c -o out` and fix every warning — GATE-relevant bugs (uninitialized pointers, missing `free`, wrong `sizeof`) usually show up as warnings first.

---

## Day 1 — Pointers

1. Write a program to swap two integers using pointers (a `swap(int*, int*)` function, called from `main`).
2. Write a program that prints all elements of an array **using only pointer arithmetic** (`*(p+i)` style) — no `arr[i]` indexing anywhere.
3. Write a program to find the sum and average of `n` array elements by walking the array with a pointer (increment the pointer itself, don't index).
4. Write a program using a pointer-to-pointer: dynamically allocate an `int`, store its address in a pointer `p`, store `p`'s address in a double pointer `pp`, then modify the value only through `pp` and print it via all three (`*p`, `**pp`, and the original variable if any).
5. Write a program to reverse an array **in place** using two pointers — one starting at the first element, one at the last — swapping and moving inward until they meet.

---

## Day 2 — Arrays & 2D Arrays

1. Write a function `int findMax(int *arr, int n)` that returns the maximum element, called from `main` with a normal array — implement it using pointer traversal, not indexing.
2. Write a program to add two `m x n` matrices (2D arrays) and print the result.
3. Write a program to multiply two matrices (`m x n` and `n x p`) using triple nested loops.
4. Write a program to transpose a square matrix **in place** (don't use a second matrix).
5. Write a program that takes `rows` and `cols` as input, dynamically allocates a 2D array using `malloc` (array-of-pointers technique: `int **arr = malloc(rows * sizeof(int*))`, then each row separately), fills it with user input, prints it, then frees every row and the outer array correctly.

---

## Day 3 — Dynamic Memory

1. Write a program that takes `n` as input, dynamically allocates an array of `n` integers with `malloc`, fills it via input, prints it, then frees it.
2. Write a program implementing a resizable dynamic array: start with capacity 2, and every time it's full, double the capacity using `realloc` before inserting the next element. Insert 10 elements one by one and print the final array along with final capacity.
3. Write a program that allocates an array of 5 integers using `calloc` and prints it **before assigning any values**, to show it's zero-initialized (then contrast by doing the same with `malloc` and printing the garbage values).
4. Write a program that `malloc`s an array of 5 ints, fills it, then `realloc`s it to size 10, fills the new 5 slots, and prints all 10 — verify the first 5 values are preserved.
5. Write a program that dynamically allocates memory for a `struct Student { char name[50]; int roll; float marks; }`, takes input for one student, prints it, then frees it.

---

## Day 4 — Structures & Linked Lists

1. Define `struct Node { int data; struct Node *next; };`. Write a function `insertAtHead` that mallocs a new node and inserts it at the front of the list; insert 5 values and print the list.
2. Write a function `insertAtTail` for the same struct that adds a new node at the end of the list (handle both empty-list and non-empty-list cases).
3. Write a function `printList` that traverses and prints all elements of a singly linked list, and a function `countNodes` that returns the number of nodes.
4. Write a function `deleteNode(struct Node **head, int key)` that deletes the first node containing `key` from the list, correctly freeing its memory and re-linking the list (handle deleting the head node as a special case).
5. Write a function `reverseList` that reverses a singly linked list **iteratively** (using a loop with `prev`, `curr`, `next` pointers — no recursion, no extra list).

---

## Day 5 — Recursion

1. Write a recursive function `factorial(int n)`.
2. Write a recursive function `fib(int n)` for the nth Fibonacci number, and print `fib(0)` through `fib(10)`.
3. Write a **recursive** function `reverseListRecursive(struct Node *head)` that reverses a singly linked list (reuse the struct from Day 4) — contrast this with your iterative version from Day 4, Q5.
4. Write a recursive `binarySearch(int *arr, int low, int high, int key)` function on a sorted array, returning the index or -1.
5. Write a recursive function `sumOfDigits(int n)` that returns the sum of digits of `n`, and a recursive `power(int base, int exp)` function computing `base^exp`.

---

## Day 6 — Strings, Function Pointers, Bit Manipulation

1. Write a program to check whether a given string is a palindrome, using two pointers (one from the start, one from the end) — do **not** use `strrev` or any `string.h` reverse helper.
2. Write your own versions of `strlen`, `strcpy`, and `strcmp` from scratch (no `string.h`), and test each against the real library function on a few sample strings to confirm they match.
3. Write a simple calculator program using an **array of function pointers**: define `add`, `sub`, `mul`, `divide` functions (each `int f(int,int)`), store them in an array indexed 0–3, take the user's choice and two numbers as input, and call the correct function via the array.
4. Write a function `countSetBits(unsigned int n)` that counts the number of 1s in the binary representation of `n` using bitwise operators (`&`, `>>`) — no loops over string representations.
5. Write a program that (a) swaps two integers using XOR, with no temporary variable, and (b) checks whether a given integer is a power of 2 using the `n & (n-1)` trick — print results for a few test cases including edge cases like 0 and 1.

---

**After finishing all 30:** pick one question per day at random and re-implement it from a blank file, no notes. If you can do that cleanly, you're ready to move on to actual DSA implementations in C (stacks, queues, BSTs, graphs) — happy to build that 30-question set next.
