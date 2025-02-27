#include <algorithm>
#include <climits>
#include <iostream>
#include "Frag.hpp"
#include <string>
#include <vector>
using namespace std;


const unsigned int DEFAULT_SIZE = 179;

class HashTable {

private:
    // Define structures to hold bids
    struct Node {
        Frag frag;
        unsigned int key;
        Node* next;

        // default constructor
        Node() {
            key = UINT_MAX; //Key acts as indicator that cell has not yet been occupied
            next = nullptr;
        }

        // initialize with a bid
        Node(Frag aFrag) : Node() {
            frag = aFrag;
        }

        // initialize with a bid and a key
        Node(Frag aFrag, unsigned int aKey) : Node(aFrag) {
            key = aKey;
        }
    };

    vector<Node> nodes;

    unsigned int tableSize = DEFAULT_SIZE;

    unsigned int hash(int key);

public:
    HashTable();
    HashTable(unsigned int size);
    virtual ~HashTable();
    void Insert(Frag frag);
    void PrintAll();
    void Remove(string fragName);
    Frag Search(string fragName);
};