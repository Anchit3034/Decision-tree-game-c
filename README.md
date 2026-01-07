# Decision-tree-game-c
A learning-based guessing game in **C** using Binary-decision-tree, pointers and dynamic memory management.
This project aim is to understand how **tree data structure and decision logic work at a low level**.

---

## Project overview
The program asks a sequence of yes/no questions to guess an object the user is thinking of.(Kinda like: akinator)
Each question represents a **node** in a binary decision tree.

-Based on user input, the program traverse **yes or no**
-Leaf nodes represent final guesses.
-The structure demonstrates how decision trees work internally as a data structure.

----

## Core Concepts Used
-**Binary Decision Tree**.
-**Recursion** for deallocate memory.
-**Pointers** to link tree nodes.
-**Dynamic memory allocation** using 'malloc' (to allocate) and 'free' (to deallocate memory).
-Conditional branching and control flow.

----

## Implementation Details
-Each node is represented using a 'struct' containing:
  -Data(question or guess)
  -Pointer to yes child
  -Pointer to no child
-Nodes are allocated dynamically on the heap.
-Memory is manually managed to avoid leaks.

This project focuses on **understanding how abstract data structures map to real memory** in **C**.

---

## How to compile  and run

```bash
gcc main.c -o a.out
./a.out