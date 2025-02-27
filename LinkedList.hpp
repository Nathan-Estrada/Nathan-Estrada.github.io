#include <algorithm>
#include <iostream>
#include "Frag.hpp"

using namespace std;

class LinkedList {

private:
    //Internal structure for list entries, housekeeping variables
    struct Node {
        Frag frag;
        Node* next;

        // default constructor
        Node() {
            next = nullptr;
        }

        // initialize with a bid
        Node(Frag aFrag) {
            frag = aFrag;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size = 0;

public:
    LinkedList();
    virtual ~LinkedList();
    void Append(Frag frag);
    void Prepend(Frag frag);
    void PrintList();
    void Remove(string fragName);
    Frag Search(string fragName);
    int Size();
};