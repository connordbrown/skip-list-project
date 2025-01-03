#include <iostream>
#include "./SkipList.h"

using namespace std;

void sample() {

    // VISUAL TESTING
    SkipList list;
    list.set_level(1);

    node* head = list.init_node("HEAD", "");   
    list.set_head(head);

    node* top = list.init_node("almond", "brown");
    node* node0 = list.init_node("apple", "red");
    node* node1 = list.init_node("banana", "yellow");
    node* node2 = list.init_node("grape", "green");
    node* node3 = list.init_node("tangerine", "orange");

    
    // 1: HEAD -> almond -> banana -> tangerine -> NULL
    // 0: HEAD -> almond -> apple -> banana -> grape -> tangerine -> NULL
    head->next_ptrs.at(0) = top;
    head->next_ptrs.at(1) = top;

    top->next_ptrs.at(1) = node1; 
    top->next_ptrs.at(0) = node0;

    node0->next_ptrs.at(0) = node1;
    node1->next_ptrs.at(1) = node3;

    node1->next_ptrs.at(0) = node2;
    node2->next_ptrs.at(0) = node3;

    list.insert("grape", "purple");

    // insert more new fruits
    // acai -> almond -> apple -> banana -> grape -> pear -> tangerine -> NULL
    list.insert("acai", "red");
    list.insert("pear", "white");
    cout << endl;
    cout << list.report() << endl;

    list.remove("pear");
    list.insert("watermelon", "red");
    list.insert("dragonfruit", "green");

    cout << list.report() << endl;

}
