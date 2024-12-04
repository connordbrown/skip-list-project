#include "SkipList.h"

// constructor
SkipList::SkipList() {
    head_ptr = NULL;
    list_level = 0;
}

// destructor
SkipList::~SkipList() {}

// create and initialize new node
node* SkipList::init_node(string key, string data) {
    // allocate memory for ret
    node* ret = new node;

    // assign key and data to ret, set next pointer to NULL
    ret->key = key;
    ret->data = data;
    ret->next = NULL;
    
    return ret;
}