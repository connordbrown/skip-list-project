#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <string>
#include <vector>
#include <ctime>
#include <random>
#include <iostream>

using namespace std;

struct node {
    string key = ""; // search key
    string data = ""; // node data
    vector<node*> next_ptrs; // array of forward pointers
};

class SkipList {
    private:
        node* head_ptr; // head of list
        int list_level; // current maximum level of list
        int MAX_LEVEL; // absolute maximum level of list

    public:
        SkipList();
        ~SkipList();

        node* get_head();
        void set_head(node* head_ptr);

        int get_level();
        void set_level(int new_level);

        node* init_node(string key, string data);
        double get_random_decimal();
        int get_random_level();

        node* find(node* current, string search_key, vector<node*>& update);
        void insert(string search_key, string new_data);
        void remove(string search_key);
        
        string report();
        int size();
        bool contains(string search_key);
};

#endif // SKIPLIST_H