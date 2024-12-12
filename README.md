# skip-list-project

## introduction

This project is a C++ implementation of a Skip List.

A Skip List is a specialized form of a Linked List that uses multiple ordered Linked List "levels" to search for, insert, and delete elements. This is done through each node having multiple forward pointers. The levels enable “skipping” over large sections of the list. The benefit that comes from such a design is that Skip Lists have an average runtime complexity of O(log n) for all CRUD operations. In other words, they have the speed and efficiency of a Binary Search Tree, but the simplicity of a linear List data type. They are used in things like calendars, event scheduling, large dictionaries, and stock market tickers.

For example:

```text
Level 3: HEAD -> 6 -> NULL
Level 2: HEAD -> 6 -> 25 -> NULL
Level 1: HEAD -> 6 -> 9 -> 25 -> NULL
Level 0: HEAD -> 3 -> 6 -> 7 -> 9 -> 12 -> 19 -> 21 -> 25 -> 26 -> NULL
```

Level 0 contains all elements of the list. Traversing it as is would give a time complexity of O(n) using standard Linked List iteration. If we searched for 25 in this manner, the search path would include 8 nodes:

```text
3 -> 6 -> 7 -> 9 -> 12 -> 19 -> 21 -> 25
```

However, if we start at Level 3 and make our way down the levels using Skip List iteration, we can skip over many of the nodes of the list. The search path only uses 2 nodes.

```text
6 -> 25
```

This search is much faster.

For my implementation and demonstration, I used a common ordered set of data: an English dictionary. The nodes contain words and their definitions, and I record the time it takes to perform CRUD operations (search, insert, update, and delete). If my implementation is correct, then the runtimes will grow logarithmically with the size of the Skip List, proving the Skip List is a fast and viable alternative to a balanced tree data structure.

### *key functions: SkipList class*

- **find(string search_key, string new_data)**: searches for and returns a node with given search_key while updating pointers in update array - helper for insert() and delete().

- **insert(string search_key, string new_data)**: inserts a new node into the list, or updates node data if key already in list.

- **remove(string search_key)**: removes a node from the list.

- **contains(string search_key)**: determines whether or not list contains a key and can be modified to print search path.

### *node structure*

- **string key**: search key of node.

- **string data**: values/data contained in node.

- **vector<node*>** next_ptrs: list of forward pointers to next nodes in list.


## operation

This application uses C++17 or later via CMake. Build it with the following commands:

```text
cd build
cmake ..
```

Then, compile and run it:
```bash
make && ./run_app
```

## sample output
```text
Check back soon!
```

## author

Written by Connor D. Brown in 2024.

## references

Black, Paul E. "skip list." In Dictionary of Algorithms and Data Structures, edited by Paul E. Black. [Online]. National Institute of Standards and Technology, August 19, 2019. Accessed December 10, 2024. https://www.nist.gov/dads/HTML/skiplist.html.

[dwyl]. (2024, December 10). english-words [Computer software]. GitHub repository. https://github.com/dwyl/english-words

Pugh, William. "Skip lists: a probabilistic alternative to balanced trees." Communications of the ACM 33, no. 6 (1990): 668-676.

*Wikipedia, "Skip list," December 10, 2024. [Online]. Accessed December 10, 2024.  https://en.wikipedia.org/wiki/Skip_list



