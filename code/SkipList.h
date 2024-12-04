#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <string>

using namespace std;

struct node {
    string key;
    string val;
    node* next[1];
};



#endif // SKIPLIST_H