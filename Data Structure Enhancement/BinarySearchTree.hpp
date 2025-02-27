#include <iostream>
#include "Frag.hpp"
using namespace std;

struct Node {
    Frag frag;
    Node* left;
    Node* right;

    // default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // initialize with a fragrance
    Node(Frag aFrag) :
        Node() {
        this->frag = aFrag;
    }
};

class BinarySearchTree {

private:
    Node* root;

    void addNode(Node* node, Frag frag);
    void inOrder(Node* node);
    void preOrder(Node* node);
    void postOrder(Node* node);
    Node* removeNode(Node* node, string fragName);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void InOrder();
    void Insert(Frag frag);
    void PostOrder();
    void PostOrder(Frag frag);
    void PreOrder();
    void PreOrder(Frag frag);
    void Remove(string fragName);
    Frag Search(string fragName);
};


