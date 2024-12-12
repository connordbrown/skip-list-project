#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "../code/SkipList.h"

using namespace std;

int main(){
    // NOTES FOR APPLICATION
    /*
    Test using dictionary of words
    Insert 10, 100, 1000, 10000, 100000, 200000, 300000, 400000 words
    Delete word from each of those
    Track time taken for process to prove logarithmic time wrt list size
    */

    string filename = "../words.txt"; // Replace with your filename
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        // while (getline(file, line)) {
        //     std::cout << line << std::endl;
        // }
        for (unsigned int i = 0; i < 20; ++i) {
            getline(file, line);
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file " << filename << endl;
    }





    return 0;
}