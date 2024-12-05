#ifndef SKIPLIST_H
#define SKIPLIST_H

#define MAX_LEVEL 15
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct node {
    string key;
    string data;
    // points to array of pointers
    vector<node*> next_ptrs;
};

class SkipList {
    private:
        node* head_ptr;
        int list_level;

    public:
        SkipList();
        ~SkipList();
        node* get_head();
        int get_level();
        void set_level(int new_level);
        node* init_node(string key, string data);
        void insert(node* new_node);
        void insert_data(string key, string data);
        void remove(string key);
        string report();
        int size();
        bool contains(string key);
        void set_head(node* head_ptr);
};

#endif // SKIPLIST_H