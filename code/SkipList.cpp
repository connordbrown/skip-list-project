#include "SkipList.h"

// constructor
SkipList::SkipList() {
    head_ptr = NULL;
    list_level = 0;
    MAX_LEVEL = 15;
}

// destructor
SkipList::~SkipList() {}

// get head node
node* SkipList::get_head() {
    return this->head_ptr;
}

// set head node
void SkipList::set_head(node* head_ptr) {
    this->head_ptr = head_ptr;
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

    // ret->next_ptrs is unchanged
    ret->next_ptrs.resize(MAX_LEVEL + 1, NULL);
    
    return ret;
}

double SkipList::get_random_decimal() {
    // seed random number generator with current time
    srand(time(NULL));

    // generate a random number in the range [0...1)
    double random_decimal = static_cast<double>(rand()) / (RAND_MAX + 1);

    if (random_decimal < 0) {
        return (-1 * random_decimal);
    }
    return random_decimal;
}

int SkipList::get_random_level() {
    int level = 0;
    // fraction of nodes with level i pointers that also have level i + 1 pointers
    int p_dist = 0.5;




}

// insert a new node into the list
void SkipList::insert(node* new_node) {
    // node* current = get_head();
    // vector<node*> update(MAX_LEVEL + 1, NULL);
    // srand(time(NULL));
    // int new_level;

    // // if list is empty
    // if (current == NULL) {
    //     current = new_node;
    //     this->set_level(0); // Set the initial level
    //     return; // No need to proceed further 
    // }

    // for (unsigned int i = get_level(); i >= 0; --i) {
    //     while (current->next_ptrs.at(i) != NULL && current->next_ptrs.at(i)->key < current->key) {
    //         current = current->next_ptrs.at(i);
    //     }
    //     update.at(i) = current;
    // }
    // current = current->next_ptrs.at(0);

    // // key already in list - update data only
    // if (current != NULL && current->key == new_node->key) {
    //     current->data = new_node->data;
    //     return;
    // }

    // // key not in list

    // // determine level
    // for (new_level = 0; rand() < RAND_MAX / 2 && new_level < MAX_LEVEL; ++new_level) {
    //     if (new_level > get_level()) {
    //         for (int i = get_level() + 1; i <= new_level; ++i) {
    //             update.at(i) = NULL;
    //         }
    //         set_level(new_level);
    //     }
    // }

    // // update forward links
    // for (int i = 0; i < new_level; ++i) {
    //     current->next_ptrs.at(i) = update.at(i)->next_ptrs.at(i);
    //     update.at(i)->next_ptrs.at(i) = current;
    // }
}

// initialize data of and allocate memory for new_node and insert new_node into list
void SkipList::insert_data(string key, string data) {
    node* new_node = init_node(key, data);
    this->insert(new_node);
}

void SkipList::remove(string key) {

}

string SkipList::report() {
    return "";
}

int SkipList::size() {
    return -1;
}

bool SkipList::contains(string search_key) {
    node* current = get_head();
    for (int i = get_level(); i >= 0; --i) {
        while (current->next_ptrs.at(i) != NULL && current->next_ptrs.at(i)->key < search_key) {
            current = current->next_ptrs.at(i);
        }
    }
    // reach level containing search_key
    current = current->next_ptrs.at(0);
    if (current != NULL && current->key == search_key) {
        return true;
    }
    return false;
}