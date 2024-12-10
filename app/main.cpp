#include <iostream>
#include "../code/SkipList.h"

using namespace std;

int main(){

    SkipList list;
    list.set_level(1);

    node* top = list.init_node("apple", "red");
    list.set_head(top);

    node* node1 = list.init_node("banana", "yellow");
    node* node2 = list.init_node("grape", "green");
    node* node3 = list.init_node("tangerine", "orange");
    
    // apple -> banana -> tangerine -> NULL
    // apple -> banana -> grape -> tangerine -> NULL
    top->next_ptrs.at(0) = node1;
    node1->next_ptrs.at(0) = node2;
    node1->next_ptrs.at(1) = node3;
    node2->next_ptrs.at(0) = node3;

    cout << node2->data << endl;
    // update grape color
    list.insert("grape", "purple");
    cout << node2->data << endl;

    // apple -> banana -> grape -> pear -> tangerine -> NULL
    // insert new fruit
    list.insert("pear", "white");
    cout << list.contains("pear") << endl;

    list.remove("pear");
    cout << list.contains("pear") << endl;

    list.insert("peaa", "white");
    list.insert("peab", "white");
    list.insert("peac", "white");

    cout << list.report() << endl;
    cout << list.size();
    // FIXME: for search, insert and delete: test beginning, middle and end


    return 0;
}