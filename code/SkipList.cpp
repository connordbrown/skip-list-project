#include "SkipList.h"

// constructor
SkipList::SkipList() {
    head_ptr = NULL;
    list_level = 0;
}

// destructor
SkipList::~SkipList() {}

// create and initialize new node
node* SkipList::init_node(string key, string data, node** next_ptrs) {
    // allocate memory for ret
    node* ret = new node;

    // assign key, data, and next to ret
    ret->key = key;
    ret->data = data;
    ret->next_ptrs = next_ptrs;
    
    return ret;
}