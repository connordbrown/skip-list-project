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

// generate a random decimal in the range [0...1)
double SkipList::get_random_decimal() {
    static mt19937 rng(random_device{}());
    static uniform_real_distribution<double> dist(0.0, 0.9999);
    return dist(rng);
}

// generate a random level in the range [0, MAX_LEVEL]
int SkipList::get_random_level() {
    int level = 0;
    // fraction of nodes with level i pointers that also have level i + 1 pointers
    double p_dist = 0.5;
    
    // get initial random decimal value
    double random_decimal = get_random_decimal();

    // increment level based on distribution of random numbers
    while (random_decimal < p_dist && level < MAX_LEVEL) {
        level = level + 1;
        random_decimal = get_random_decimal();
    }

    return level;
}

// insert a new node into the list
void SkipList::insert(string search_key, string new_data) {
    node* current = get_head();
    vector<node*> update(MAX_LEVEL + 1, NULL);

    // if list is empty
    if (current == NULL) {
        current = init_node(search_key, new_data);
        // set initial level
        set_level(0);
        return;
    }

    for (int i = get_level(); i >= 0; --i) {
        while (current->next_ptrs.at(i) != NULL && current->next_ptrs.at(i)->key < search_key) {
            current = current->next_ptrs.at(i);
        }
    }
    // reach level containing search key
    current = current->next_ptrs.at(0);

    // if key in list, update value
    if (current != NULL && current->key == search_key) {
        current->data = new_data;
    }
    // else insert new_node
    else {
        int rand_lvl = get_random_level();
        if (rand_lvl > get_level()) {
            for (int i = get_level() + 1; i < rand_lvl; ++i) {
                update.at(i) = get_head();
            }
            set_level(rand_lvl);
        }
        node* new_node = init_node(search_key, new_data);
        // update forward pointers
        for (int i = 0; i < get_level(); ++i) {
            update.at(i) = get_head();
            new_node->next_ptrs.at(i) = update.at(i)->next_ptrs.at(i);
            update.at(i)->next_ptrs.at(i) = new_node;
        }
    }

}

// initialize data of and allocate memory for new_node and insert new_node into list
// void SkipList::insert_data(string key, string data) {
//     node* new_node = init_node(key, data);
//     this->insert(new_node);
// }

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