#include <iostream>
#include <time.h>

#include "BinarySearchTree.hpp"
#include "HashTable.hpp"
#include "LinkedList.hpp"
#include "Frag.hpp"

#include "CSVparser.hpp"

using namespace std;
/**/

// Define a timer variable
clock_t ticks;


/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

// Display the fragrance information to the console (std::out)
void displayFrag(Frag frag) {
    cout << frag.fragBrand << "| " << frag.fragName << " | " << frag.fragPrice << endl;
    return;
}
/**
 * Load a CSV file into Binary Search Tree
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the fragrances read
 */
void loadBST(string csvPath, BinarySearchTree* bst) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    // read and display header row - optional
    vector<string> header = file.getHeader();
    for (auto const& c : header) {
        cout << c << " | ";
    }
    cout << "" << endl;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of fragrances
            Frag frag;
            frag.fragBrand = file[i][0];
            frag.fragName = file[i][1];
            frag.fragPrice = stod(file[i][2]);
            // push this frag to the end
            bst->Insert(frag);
        }
    }
    catch (csv::Error& e) {
        std::cerr << e.what() << std::endl;
    }
}

// Load csv file into Hash Table
void loadHash(string csvPath, HashTable* hashTable) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    // read and display header row - optional
    vector<string> header = file.getHeader();
    for (auto const& c : header) {
        cout << c << " | ";
    }
    cout << "" << endl;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of fragrancess
            Frag frag;
            frag.fragName = file[i][1];
            frag.fragBrand = file[i][0];
            frag.fragPrice = stod(file[i][2]);
            // push this frag to the end
            hashTable->Insert(frag);
        }
    }
    catch (csv::Error& e) {
        std::cerr << e.what() << std::endl;
    }
}
//Load csv file into Linked List
void loadList(string csvPath, LinkedList* linkedList) {
    cout << "Loading CSV file " << csvPath << endl;
    // initialize the CSV Parser
    csv::Parser file = csv::Parser(csvPath);

    try {
        // loop to read rows of a CSV file
        for (int i = 0; i < file.rowCount(); i++) {

            // initialize a fragrance using data from current row (i)
            Frag frag;
            frag.fragName = file[i][1];
            frag.fragBrand = file[i][0];
            frag.fragPrice = stod(file[i][2]);


            // add this fragrance to the end
            linkedList->Append(frag);
        }
    }
    catch (csv::Error& e) {
        std::cerr << e.what() << std::endl;
    }
}
/*
* Allows users to select what data structure they want to load
* the contents of the CSV into
*/
void SelectDataStructure() {
    //Define csv path
    string csvPath = "Perfumania_Fragrances.csv";

    // Initialize a timer variable before loading fragrancess
    ticks = clock();

    Frag frag;
    int option = 0;
    int bstChoice = 0;
    int hashChoice = 0;
    int listChoice = 0;
    while (option != 9) {
        cout << "Select which data strucutre you would like to load the data into" << endl;
        cout << "1. Binary Search Tree" << endl;
        cout << "2. Hash Table" << endl;
        cout << "3. Linked List" << endl;
        cout << "9. Back" << endl;

        cin >> option;
        switch (option) {
        case 1:
            // Define a binary search tree to hold all fragrancess
            BinarySearchTree * bst;
            bst = new BinarySearchTree();

            // Complete the method call to load the fragrancess
            loadBST(csvPath, bst);

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            while (bstChoice != 3) {
                cout << "Binary Search Tree Loaded" << endl;
                cout << "Select an option" << endl;
                cout << "1. Display Data" << endl;
                cout << "2. Search Data" << endl;
                cout << "3. Back" << endl;

                cin >> bstChoice;
                switch (bstChoice) {
                case 1:
                    bst->InOrder();
                    break;
                case 2:
                    string fragName;
                    cout << "Enter a fragrance to search" << endl;
                    cin >> fragName;
                    frag = bst->Search(fragName);
                    if (!frag.fragName.empty()) {
                        displayFrag(frag);
                    }
                    else {
                        cout << "Could not find " << fragName << " in database." << endl;
                    }
                    break;
                }
            }
            break;
        case 2:
            //Define a hash table to hold all fragrances
            HashTable * table;
            table = new HashTable();

            loadHash(csvPath, table);
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            while (hashChoice != 3) {
                cout << "Hash Table Loaded" << endl;
                cout << "Select an option" << endl;
                cout << "1. Display Data" << endl;
                cout << "2. Search Data" << endl;
                cout << "3. Back" << endl;

                cin >> hashChoice;
                switch (hashChoice) {
                case 1:
                    table->PrintAll();
                    break;
                case 2:
                    string fragName;
                    cout << "Enter a fragrance to search" << endl;
                    cin >> fragName;
                    table->Search(fragName);
                    if (!frag.fragName.empty()) {
                        displayFrag(frag);
                    }
                    else {
                        cout << "Could not find " << fragName << " in database." << endl;
                    }
                    break;
                }
            }
            break;
        case 3:
            //Define a linked list to hold all fragrances
            LinkedList * linkedList;
            linkedList = new LinkedList();

            loadList(csvPath, linkedList);
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            while (listChoice != 3) {
                cout << "Linked List Loaded" << endl;
                cout << "Select an option" << endl;
                cout << "1. Display Data" << endl;
                cout << "2. Search Data" << endl;
                cout << "3. Back" << endl;

                cin >> listChoice;
                switch (listChoice) {
                case 1:
                    linkedList->PrintList();
                    break;
                case 2:
                    string fragName;
                    cout << "Enter a fragrance to search" << endl;
                    cin >> fragName;
                    linkedList->Search(fragName);
                    if (!frag.fragName.empty()) {
                        displayFrag(frag);
                    }
                    else {
                        cout << "Could not find " << fragName << " in database." << endl;
                    }
                    break;
                }
            }
            break;
        }
    }
}
int main(int argc, char* argv[]) {
    int choice = 0;
    while (choice != 2) {
        cout << "Menu:" << endl;
        cout << "  1. Select data structure" << endl;
        cout << "  2. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            SelectDataStructure();
            break;
        }
    }
    cout << "Good bye." << endl;
    return 0;
}