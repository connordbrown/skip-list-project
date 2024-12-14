#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "../code/SkipList.h"

using namespace std;

// extracts words from file and inserts num_items words into list
void populate_dictionary(SkipList& list, int num_items) {
    string filename = "../words.txt";
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        cout << "Populating dictionary with " << num_items << " items..." << endl;
        int count = 0;
        while (getline(file, line) && count < num_items) { 
            list.insert(line, "None");
            count++;
        }
        file.close();
        cout << "Done." << endl;
    } else {
        cerr << "Error: Unable to open file " << filename << endl;
    }
}

int main(){
    /*
    NOTES FOR APPLICATION:
    - Test Skip List using dictionaries of words
    - Insert 10, 100, 1000, 10000, and 50000 words into different lists
    - NOTE: if out of bounds error occurs during runtime, may need to increase MAX_LEVEL to raise list capacity
    - Track time taken to insert a new node at/near end of list
    */

   vector<int> list_sizes = {10, 100, 1000, 10000, 50000};
   vector<SkipList> lists;

   for (int size : list_sizes) {
        SkipList list;
        populate_dictionary(list, size);
        lists.push_back(list);
   }

   for (SkipList list : lists) {
        // declare clock and time variables
        clock_t start_time, end_time;
        double elapsed_time;

        cout << endl;
        cout << "Inserting item into dictionary of size " << list.size() << "..." << endl;

        // get the start time
        start_time = clock();

        // insert an item
        list.insert("zebra", "None");

        cout << "Done." << endl;

        // get the end time
        end_time = clock();

        // calculate and print the elapsed time
        elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000.0;

        cout << "Elapsed time for insert: " << elapsed_time << " milliseconds" << endl;
        cout << endl;
   }

    return 0; // end main
}