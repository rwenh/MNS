# Data Structures & Algorithms Learning Library (`dsa_learning`)

A modular **C11** learning repository implementing core Data Structures and Algorithms from scratch.  
Designed with clear separation of API headers, source implementations, CMake build system, and an executable driver.

---

## Project Layout

```text
dsa_learning/
├── CMakeLists.txt          # Top-level build configuration (C11, static lib + executable)
├── README.md               # This file
├── main.c                  # Driver that exercises all modules
├── array_ops.c
├── recursion.c
├── stack_queue.c
├── linked_list.c
├── trees_bst.c
├── heap.c
├── graph.c
└── dsa/                    # Public API headers
    ├── array_ops.h
    ├── recursion.h
    ├── stack_queue.h
    ├── linked_list.h
    ├── trees_bst.h
    ├── heap.h
    └── graph.h
```

---

## Module Overview

### 1. Recursion (`dsa/recursion.h` / `recursion.c`)
- Factorial & Fibonacci
- Tower of Hanoi
- Euclidean GCD
- Fast exponentiation (handles negative exponents)
- In-place string reversal
- Combinations (`nCr`)

### 2. Dynamic Arrays & Sorting (`dsa/array_ops.h` / `array_ops.c`)
- Dynamic array with automatic resizing
- Insert / delete at arbitrary index
- Linear search & Binary search
- Bubble Sort, Insertion Sort, Quick Sort (Lomuto partition)

### 3. Stacks & Queues (`dsa/stack_queue.h` / `stack_queue.c`)
- Array-based Stack (push / pop / peek / is_empty)
- Bracket matching
- Infix → Postfix conversion (Shunting-yard)
- MinStack (O(1) get-min)
- Circular Queue

### 4. Linked Lists (`dsa/linked_list.h` / `linked_list.c`)
- Insert at head / tail, delete by value
- Iterative list reverse
- Floyd’s cycle detection
- Merge two sorted lists
- Find middle node (fast/slow pointer)

### 5. Trees & BSTs (`dsa/trees_bst.h` / `trees_bst.c`)
- Pre-order, In-order, Post-order, Level-order traversals
- Height, leaf count, mirror
- BST insert / search / delete (3-case)
- Min / Max / Range sum

### 6. Binary Heap (`dsa/heap.h` / `heap.c`)
- Min-Heap with `heapify_up` / `heapify_down`
- Insert & Extract-min
- Heap Sort

### 7. Graphs (`dsa/graph.h` / `graph.c`)
- Weighted adjacency-list representation
- BFS & DFS
- Dijkstra’s single-source shortest path

---

## Building & Running

### Requirements
- C compiler supporting C11 (`gcc` or `clang`)
- CMake ≥ 3.10
- `make` (or Ninja)

### Steps

```bash
mkdir build && cd build
cmake ..
make
./dsa_runner
```

This produces:
- `libdsa_core.a` – static library containing all DSA modules
- `dsa_runner`   – executable that demonstrates the modules

---

## Roadmap

- [x] **Phase 1** – Core DSA primitives + CMake build
- [ ] **Phase 2** – Unit tests (CTest) + AddressSanitizer / UBSan
- [ ] **Phase 3** – AVL trees, Topological Sort, Union-Find
- [ ] **Phase 4** – Custom arena allocator & generic `void*` containers
