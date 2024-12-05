#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

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
        int MAX_LEVEL;

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
        void insert(node* new_node);
        void insert_data(string key, string data);
        void remove(string key);
        
        string report();
        int size();
        bool contains(string search_key);
};

#endif // SKIPLIST_H