#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <string>

using namespace std;

struct node {
    string key;
    string val;
    // points to array of pointers
    node** next;
};

class SkipList {
    public:
        SkipList();
        ~SkipList();
        node* init_node(string key, string val);
        string report();
        void insert();
        void insert_data();
        void remove();
        void remove_data();
        int size();
        bool contains(string key);
        node* get_head();
        void set_head(node* head_ptr);

    private:
        node* head_ptr;
        int list_level;
};


#endif // SKIPLIST_H