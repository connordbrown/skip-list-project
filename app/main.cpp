#include <iostream>
#include "../code/SkipList.h"

using namespace std;

int main(){

    SkipList list;
    list.set_level(1);

    //node* top = list.init_node("apple", "red");
    node* top = list.init_node("HEAD", "");
    list.set_head(top);

    node* node0 = list.init_node("apple", "red");
    node* node1 = list.init_node("banana", "yellow");
    node* node2 = list.init_node("grape", "green");
    node* node3 = list.init_node("tangerine", "orange");
    
    // HEAD -> banana -> tangerine -> NULL
    // HEAD -> apple -> banana -> grape -> tangerine -> NULL
    top->next_ptrs.at(1) = node1; 
    top->next_ptrs.at(0) = node0;

    node0->next_ptrs.at(0) = node1;
    node1->next_ptrs.at(1) = node3;

    node1->next_ptrs.at(0) = node2;
    node2->next_ptrs.at(0) = node3;

    cout << node2->data << endl;
    // update grape color
    list.insert("grape", "purple");
    cout << node2->data << endl;

    // HEAD-> apple -> banana -> grape -> pear -> tangerine -> NULL
    // insert new fruit
    list.insert("pear", "white");
    cout << list.contains("pear") << endl;

    list.remove("pear");
    cout << list.contains("pear") << endl;

    // FIXME: Why is insert() not always inserting???
    list.insert("almond", "brown");

    cout << list.report() << endl;
    cout << list.size() << endl;

    return 0;
}