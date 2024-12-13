#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "../code/SkipList.h"

using namespace std;

void populate_dictionary(SkipList& list, int num_items) {
    string filename = "../words.txt"; // Replace with your filename
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
    NOTES FOR APPLICATION
    Test using dictionary of words
    Insert 10, 100, 1000, 10000, 100000, 200000, 300000, 400000 words
    NOTE: after 10000 items, need to increase MAX_LEVEL
    Track time taken for process to prove logarithmic time wrt list size
    */

   vector<int> list_sizes = {10, 100, 1000, 10000, 50000};
   vector<SkipList> lists;

   for (int size : list_sizes) {
        SkipList list;
        populate_dictionary(list, size);
        lists.push_back(list);
   }

   for (SkipList list : lists) {
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






    return 0;
}