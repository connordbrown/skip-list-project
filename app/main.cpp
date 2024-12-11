#include <iostream>
#include <fstream>
#include <string>
#include "../code/SkipList.h"

using namespace std;

int main(){

    SkipList list;
    list.set_level(1);

    node* top = list.init_node("HEAD", "");
    list.set_head(top);

    node* node0 = list.init_node("apple", "red");
    node* node1 = list.init_node("banana", "yellow");
    node* node2 = list.init_node("grape", "green");
    node* node3 = list.init_node("tangerine", "orange");
    
    // 1: HEAD -> banana -> tangerine -> NULL
    // 0: HEAD -> apple -> banana -> grape -> tangerine -> NULL
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

    list.insert("pear", "white");
    cout << list.report() << endl;

    list.remove("pear");

    cout << list.report() << endl;
    cout << list.size() << endl;





    // NOTES FOR APPLICATION
    /*
    Test using dictionary of words
    Insert 10, 100, 1000, 10000, 100000, 200000, 300000, 400000 words
    Delete word from each of those
    Track time taken for process to prove logarithmic time wrt list size

    // string filename = "words.txt"; // Replace with your filename
    // ifstream file(filename);

    // if (file.is_open()) {
    //     string line;
    //     while (getline(file, line)) {
    //         std::cout << line << std::endl;
    //     }
    //     file.close();
    // } else {
    //     cerr << "Error: Unable to open file " << filename << endl;
    // }

    */

    return 0;
}