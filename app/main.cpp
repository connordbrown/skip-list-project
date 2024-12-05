#include <iostream>
#include "../code/SkipList.h"

using namespace std;

int main(){

    SkipList list;

    node* top = list.init_node("apple", "red");
    list.set_head(top);

    node* node1 = list.init_node("banana", "yellow");
    node* node2 = list.init_node("grape", "green");
    node* node3 = list.init_node("tangerine", "orange");
    
    // apple -> banana -> tangerine -> NULL
    // apple -> banana -> grape -> tangerine -> NULL
    top->next_ptrs.push_back(node1);
    node1->next_ptrs.push_back(node2);
    node1->next_ptrs.push_back(node3);
    node2->next_ptrs.push_back(node3);
    node3->next_ptrs.push_back(NULL);

    node* current = list.get_head();
    cout << current->key << endl;

    // while (current != NULL) {
    //     cout << current->key << endl;
    //     current = current->next_ptrs.at(0); // Traverse at level 0
    // }



    return 0;
}