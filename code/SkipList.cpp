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

// set list level
void SkipList::set_level(int new_level) {
    this->list_level = new_level;
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
    srand(time(0));
    int new_level;
    for (unsigned int i = get_level(); i >= 0; --i) {
        while (current->next_ptrs.at(i) != NULL && current->next_ptrs.at(i)->key < current->key) {
            current = current->next_ptrs.at(i);
        }
        update.at(i) = current;
    }
    current = current->next_ptrs.at(0);

    // key already in list
    if (current != NULL && current->key == new_node->key) {
        return;
    }

    // determine level
    for (new_level = 0; rand() < RAND_MAX / 2 && new_level < MAX_LEVEL; ++new_level) {
        if (new_level > get_level()) {
            for (int i = get_level() + 1; i <= new_level; ++i) {
                update.at(i) = NULL;
            }
            set_level(new_level);
        }
    }

    // update forward links
    for (int i = 0; i < new_level; ++i) {
        current->next_ptrs.at(i) = update.at(i)->next_ptrs.at(i);
        update.at(i)->next_ptrs.at(i) = current;
    }
}

// initialize data of and allocate memory for new_node and insert new_node into list
void SkipList::insert_data(string key, string data) {
    node* new_node = init_node(key, data);
    this->insert(new_node);
}