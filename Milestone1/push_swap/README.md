*This project has been created as part of the 42 curriculum by smarin-s and exia*

# push_swap (42 project)

## Description

push_swap is a small sorting project that implements an integer-sorting program using two stacks and a limited set of stack operations. The goal is to produce a sequence of allowed operations that sorts the input list while minimizing the total number of operations. This repository contains two executables: `push_swap` (produces a sequence of operations) and a simple `checker` utility (validates a sequence of operations).

This implementation includes several strategies for different input sizes and disorder levels: a simple selection-based strategy, a chunk-based medium strategy, a radix-like complex strategy based on index bits, and an adaptative strategy that picks the best algorithm at runtime.

## Algorithms — explanation and justification

The project includes these algorithmic strategies. For each I explain what it does and why it was chosen.

1) Simple strategy (selection-style)
- Description: Repeatedly find the minimum element in stack A, rotate A until the minimum is on top, push it to B, and then push back all elements from B to A.
- Justification: This approach is simple and works well for very small inputs (e.g., n ≤ 3–5). It is easy to implement and produces a small number of moves for tiny lists. Complexity: O(n^2) comparisons/rotations in the worst case, but n is small so this is acceptable.

2) Medium strategy (chunk decomposition)
- Description: Normalize the input values to indices, split indices into chunks, and push chunks from A to B (moving elements that fall within each chunk). After each chunk is in B, push back the values to A in order by repeatedly rotating B to bring the max value to top and pushing it to A.
- Justification: Chunking reduces the number of rotations and searches by restricting movement to ranges. It balances the cost of scanning and rotation and is an effective compromise for medium-sized inputs (e.g., up to ~100 elements). Complexity: roughly O(n * chunks) where chunk count is tuned based on n; practical performance is good when chunk size is tuned.

3) Complex strategy (radix on indices)
- Description: Normalize values to ranks (0..n-1) and process bit by bit from least-significant to most-significant: for each bit, push elements whose bit is 0 to B and rotate elements with bit 1 in A; then move all elements back from B to A. Repeat for all bits necessary to represent the maximum index.
- Justification: This is effectively a binary radix sort applied with stack operations. The algorithm is O(n * log n) in the number of bits and scales well to large inputs (e.g., several hundreds to thousands). It is deterministic and simple to reason about using only allowed operations.

4) Adaptative strategy
- Description: Compute a simple disorder metric (fraction of inverted pairs). Based on this metric, choose between the simple, medium or complex strategies to reduce overall operations for a given input.
- Justification: Different strategies are preferable depending on `n` and how unordered the input is. An adaptative selector chooses the expected-best algorithm at runtime. This improves average-case behavior across diverse inputs.

Normalization (indexing)
- For medium and complex strategies we normalize values into ranks (0..n-1). This avoids dealing with absolute values and allows algorithms to reason about order and use bitwise operations efficiently.

## Instructions (compilation and execution)

Requirements
- A POSIX system (Linux/macOS).
- A C compiler (gcc/clang), `make`, and standard build tools.

Build

```bash
# from project root
make
```

This builds `push_swap` (and the libft and ft_printf helper libraries used by the project). The produced binary is `./push_swap`.

Quick usage examples

```bash
# produce moves to sort the list
./push_swap 3 2 1 0

# run checker (example, if you have a file of moves or pipe)
./push_swap 3 2 1 0 | ./checker 3 2 1 0

# use flags for bench/strategy control
./push_swap --bench --simple 3 2 1 0
./push_swap --bench --adaptative 42 12 8 6
```

Flags
- `--bench` : enable collection and printing of simple benchmark statistics (disorder, operations counts, etc.).
- `--simple`, `--medium`, `--complex`, `--adaptative` : force the chosen strategy. If no strategy flag is provided, the adaptative strategy is selected by default.

Memory and correctness checks

You can run Valgrind to check for leaks (example):

```bash
valgrind --leak-check=full ./push_swap 42 13 7 2
```

## Features and structure

- `main.c` — argument parsing, top-level program flow, bench allocation.
- `includes/push_swap.h` — public prototypes and shared types (`t_stack`, `t_bench`).
- `src/push_swap/` — algorithms, helpers, and movement implementations. Subfolder `moves/` implements atomic stack operations (sa, sb, pa, pb, ra, rb, rra, rrb, ss, rr, rrr).
- `src/checker/` — input validation, flags parsing, duplicate detection and benchmark wiring.
- `libft/` and `ft_printf/` — helper libraries used by the project.

## Resources

Recommended references used to implement and understand the approaches here:
- 42 Project instructions and subject (your local project page at 42 network).
- Radix sort, selection sort and general sorting algorithm references (CLRS / online resources).
- Stack-based sorting writeups and `push_swap` community resources (example tutorials and guides).

Useful links
- https://en.wikipedia.org/wiki/Radix_sort
- https://en.wikipedia.org/wiki/Selection_sort
- https://en.wikipedia.org/wiki/Sorting_algorithm
- 42 school project instructions (internal)

## Authors
- smarin-s
- exia

## License

This project is provided for educational purposes as part of the 42 curriculum. Feel free to reuse code for learning, but follow your school's rules regarding submission and collaboration.
