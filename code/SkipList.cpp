#include "SkipList.h"

// constructor
SkipList::SkipList() {
    head_ptr = NULL;
    list_level = 0;
    MAX_LEVEL = 100;
}

// destructor
SkipList::~SkipList() {}

// gets head node
node* SkipList::get_head() {
    return this->head_ptr;
}

// sets head node
void SkipList::set_head(node* head_ptr) {
    this->head_ptr = head_ptr;
}

// gets current list level
int SkipList::get_level() {
    return this->list_level;
}

// sets current list level
void SkipList::set_level(int new_level) {
    this->list_level = new_level;
}

// creates and initializes new node
node* SkipList::init_node(string key, string data) {
    // allocate memory for ret
    node* ret = new node;

    // assign key and data to ret, allocate and clear out next_ptrs
    ret->key = key;
    ret->data = data;
    ret->next_ptrs.resize(MAX_LEVEL, NULL);
    
    return ret;
}

// generates and returns a random decimal in the range [0...1)
double SkipList::get_random_decimal() {
    static mt19937 rng(random_device{}());
    static uniform_real_distribution<double> dist(0.0, 0.9999);
    return dist(rng);
}

// generates and returns a random level in the range [0, MAX_LEVEL]
int SkipList::get_random_level() {
    int level = 0;
    // fraction of nodes with level i pointers that also have level i + 1 pointers
    double p_dist = 0.5;
    
    // get initial random decimal value
    double random_decimal = get_random_decimal();

    // increment level based on probability distribution of random numbers
    while (random_decimal < p_dist && level < MAX_LEVEL) {
        level = level + 1;
        random_decimal = get_random_decimal();
    }

    return level;
}

// searches for and returns node with given search_key while adding new
// forward pointers to update array - helper for insert() and delete()
node* SkipList::find(node* current, string search_key, vector<node*>& update) {
    for (int i = get_level(); i >= 0; --i) {
        while (current->next_ptrs.at(i) != NULL && current->next_ptrs.at(i)->key < search_key) {
            current = current->next_ptrs.at(i);
        }
        // node preceding insertion/update point
        update.at(i) = current;
    }

    // reach level and node containing search key
    current = current->next_ptrs.at(0);
    
    return current;
}

// inserts a new node containing search_key and new_data into the list
// or updates existing node if search_key already in list
void SkipList::insert(string search_key, string new_data) {
    node* current = get_head();
    vector<node*> update(MAX_LEVEL + 1, NULL);

    // if list is empty
    if (current == NULL) {
        node* top = init_node("HEAD", "");
        set_head(top);
        return;
    }

    // traverse list to potential insertion point
    current = find(current, search_key, update);

    // if key in list, update value
    if (current != NULL && current->key == search_key) {
        current->data = new_data;
    }
    // else insert new_node
    else {
        // update list level
        int rand_lvl = get_random_level();
        if (rand_lvl > get_level()) {
            for (int i = get_level() + 1; i < rand_lvl; ++i) {
                update.at(i) = get_head();
            }
            set_level(rand_lvl);
        }
        // create new_node
        node* new_node = init_node(search_key, new_data);

        // update forward pointers for new_node
        for (int i = 0; i < get_level(); ++i) {
            new_node->next_ptrs.at(i) = update.at(i)->next_ptrs.at(i);
            update.at(i)->next_ptrs.at(i) = new_node;
        }
    }
}

// removes node containing search_key from the list
void SkipList::remove(string search_key) {
    node* current = get_head();
    vector<node*> update(MAX_LEVEL + 1, NULL);

    // if list is empty
    if (current == NULL) {
        return;
    }

    // traverse list to potential deletion point
    current = find(current, search_key, update);

    // if key in list
    if (current != NULL && current->key == search_key) {
        for (int i = 0; i <= get_level(); ++i) { // be careful: end condition <= instead of < like in insert()
            if (update.at(i)->next_ptrs.at(i) != current) {
                break;
            }
            // update forward pointers
            update.at(i)->next_ptrs.at(i) = current->next_ptrs.at(i);
        }
        // delete node
        delete current;

        // update list level
        while (get_level() > 0 && get_head()->next_ptrs.at(get_level()) == NULL) {
            set_level(get_level() - 1);
        }
    }
}

// generates and returns a string showing contents of each list level
string SkipList::report() {
    string ret = "";
    // iterate through levels
    for (int i = get_level() ; i >= 0; --i) {
        node* current = get_head();
        if (current == NULL) {
            return "";
        }
        ret += to_string(i) + ": "; // level number
        // get current level contents
        while (current != NULL) {
            ret += current->key + " -> ";
            current = current->next_ptrs.at(i);
        }
        ret += "NULL\n";
    }
    return ret;
}

// calculates and returns total number of nodes in list (via bottom level)
int SkipList::size() {
    node* current = get_head();
    int count = 0;
    while (current != NULL) {
        count += 1;
        current = current->next_ptrs.at(0); // 0th forward pointers indicate bottom level
    }
    return count;
}

// determines whether or not list contains a key and (optional) prints out search path
bool SkipList::contains(string search_key) {
    node* current = get_head();
    //string search_path = "";
    for (int i = get_level(); i >= 0; --i) {
        while (current->next_ptrs.at(i) != NULL && current->next_ptrs.at(i)->key < search_key) {
            //search_path += current->key + " ";
            current = current->next_ptrs.at(i);
        }
    }
    // reach level containing search_key
    current = current->next_ptrs.at(0);
    if (current != NULL && current->key == search_key) {
        //search_path += current->key;
        //cout << search_path << endl;
        return true;
    }
    return false;
}