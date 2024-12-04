#include "SkipList.h"

// constructor
SkipList::SkipList() {
    head_ptr = NULL;
    list_level = 0;
}

// destructor
SkipList::~SkipList() {}

// get head node
node* SkipList::get_head() {
    return this->head_ptr;
}

// get list level
int SkipList::get_level() {
    return this->list_level;
}

// create and initialize new node
node* SkipList::init_node(string key, string data) {
    // allocate memory for ret
    node* ret = new node;

    // assign key and data to ret, clear out next_ptrs
    ret->key = key;
    ret->data = data;
    ret->next_ptrs.clear();
    
    return ret;
}

// insert a new node into the list
void SkipList::insert(node* new_node) {
    node* current = get_head();
    vector<node*> update(MAX_LEVEL + 1, NULL);
    for (unsigned int i = get_level(); i >= 0; --i) {
        while (current->next_ptrs.at(i) != NULL && current->next_ptrs.at(i)->key < current->key) {
            current = current->next_ptrs.at(i);
        }
        update.at(i) = current;
    }
    current = current->next_ptrs.at(0);
}