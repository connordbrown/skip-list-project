#include <iostream>
#include "../code/SkipList.h"

using namespace std;

int main(){

    // Do some printing
    // int var;
    // cout << "Hello World, please enter a number " << endl;
    // cin >> var;
    // cout << "your number was : " << var << endl;
    SkipList list;
    node* top = list.init_node("apple", "red");
    list.set_head(top);
    list.insert_data("banana", "yellow");
    list.insert_data("grape", "green");
    node* current = list.get_head();
    cout << current->key << endl;

    // while (current != NULL) {
    //     cout << current->key << endl;
    //     current = current->next_ptrs.at(0); // Traverse at level 0
    // }



    return 0;
}