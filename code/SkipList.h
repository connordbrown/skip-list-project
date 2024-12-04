#ifndef SKIPLIST_H
#define SKIPLIST_H

#define MAX_LEVEL 15
#include <string>

using namespace std;

struct node {
    string key;
    string data;
    // points to array of pointers
    node** next;
};

class SkipList {
    private:
        node* head_ptr;
        int list_level;

    public:
        SkipList();
        ~SkipList();
        node* init_node(string key, string data);
        string report();
        void insert(node* new_node);
        void insert_data(string key, string data);
        void remove(string key);
        int size();
        bool contains(string key);
        node* get_head();
        void set_head(node* head_ptr);

};


#endif // SKIPLIST_H