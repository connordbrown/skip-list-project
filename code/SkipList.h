#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <string>

using namespace std;

struct node {
    string key;
    string val;
    node* next[1];
};

class SkipList {
    public:


    private:
        node* head_ptr;
        int list_level;

};


#endif // SKIPLIST_H