# push_swap
hey there
# Chunk Sort Algorithm for Push_swap

## Introduction
The main focus of the **Push_swap** project is the sorting algorithm you choose to implement. This README explains the **Chunk Sort** algorithm I use. We won't discuss basic sorting methods like Bubble Sort here, though we do use it briefly for pre-sorting.

For small cases (2 or 3 numbers), hardcoding the sorting operations is more efficient than applying a full algorithm. For example, if the stack contains only two numbers, a simple `sa` (swap a) operation is enough if they are out of order.

This document explains **Chunk Sort** for handling larger stacks (more than 5 numbers).

## Step 1: Creating and Sorting an Array
Before sorting `stack_a`, we first create an **array** from its values and sort it. This sorted array serves as a reference for sorting the stack.

For example:

```
stack_a ->   2  1  5  3  6  4
index    ->  0  0  0  0  0  0
array    ->  1  2  3  4  5  6  (sorted)
```

We then assign an **index** to each number in `stack_a`, based on its position in the sorted array:

```
stack_a ->   2  1  5  3  6  4
index    ->  1  0  4  2  5  3
array    ->  1  2  3  4  5  6
```

## Step 2: Why Assign Indexes?
Sorting works well when numbers are close to their correct positions, but what if the numbers are completely random? Assigning indexes helps us sort them systematically, regardless of their original order. `stack_b` is used as temporary storage to help with sorting.

## Step 3: Dividing into Chunks
Instead of sorting all numbers at once, we divide `stack_a` into **chunks**.

Imagine searching for a name in a **phone book** with 100 pages. Instead of checking page by page, you split it in half (50-50), then search in one half. If not found, you divide again (25-25) and continue. This is the principle behind chunking—breaking the problem into smaller, more manageable parts.

For example, if `stack_a` has 6 numbers, we divide them into smaller groups (chunks). This helps optimize sorting and reduces unnecessary operations.

## Step 4: Optimizing Moves
The final step is to **minimize operations** by making the best possible moves. The goal is to reduce the number of operations while keeping the sorting efficient.

---

This explanation provides a conceptual understanding of **Chunk Sort** in `Push_swap`. Instead of diving into code, take your time to think about the logic. Once you grasp it, the implementation will be much easier!


