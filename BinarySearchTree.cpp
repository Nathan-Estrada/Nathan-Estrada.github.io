#include "BinarySearchTree.hpp"
#include <iostream>

using namespace std;

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    // FixMe (1): initialize housekeeping variables
    //root is equal to nullptr
    root = nullptr;
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    // recurse from root deleting every node

}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
    // FixMe (2): In order root
    // call inOrder fuction and pass root
    this->inOrder(root);
}

/**
 * Traverse the tree in post-order
 */
void BinarySearchTree::PostOrder() {
    // FixMe (3): Post order root
    // postOrder root
    postOrder(root);
}

/**
 * Traverse the tree in pre-order
 */
void BinarySearchTree::PreOrder() {
    // FixMe (4): Pre order root
    // preOrder root
    preOrder(root);
}

/**
 * Insert a bid
 */
void BinarySearchTree::Insert(Frag frag) {
    // FIXME (5) Implement inserting a fragrance into the tree
    // if root equarl to null ptr
    if (root == nullptr) {
        // root is equal to new node fragrance
        root = new Node(frag);
        cout << "Root node added" << endl;
    }
    // else
    else {
        // add Node root and fragrance
        this->addNode(root, frag);
    }
}

/**
 * Remove a fragrance
 */
void BinarySearchTree::Remove(string fragName) {
    // FIXME (6) Implement removing a fragrance from the tree
    // remove node root fragName
    this->removeNode(root, fragName);
}

//Remove Node
Node* BinarySearchTree::removeNode(Node* node, string fragName) {
    //If this node is null then return (avoid crashing)
    if (node == nullptr) {
        return node;
    }
    //Recurse down left subtree
    if (fragName < node->frag.fragName) {
        node->left = removeNode(node->left, fragName);
    }
    //Recusre down right subtree
    else if (fragName > node->frag.fragName) {
        node->right = removeNode(node->right, fragName);
    }
    else {
        //No children so this is a leaf node
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
        //one child to the left
        else if (node->left != nullptr && node->right == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        //one child to the right
        else if (node->right != nullptr && node->left == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        //two children
        else {
            Node* temp = node->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            node->frag = temp->frag;
            node->right = removeNode(node->right, temp->frag.fragName);
        }
    }
    return node;
}

/**
 * Search for a fragrance
 */
Frag BinarySearchTree::Search(string fragName) {
    // FIXME (7) Implement searching the tree for a fragrance
    // set current node equal to root
    Node* current = root; //Create current node and assign root to it

    // keep looping downwards until bottom reached or matching fragName found
    while (current != nullptr) {
        // if match found, return current fragrance
        if (current->frag.fragName.compare(fragName) == 0) {
            return current->frag;
        }
        // if fragrance is smaller than current node then traverse left
        if (fragName.compare(current->frag.fragName) < 0) {
            current = current->left; //traverse left
        }
        // else larger so traverse right
        else {
            current = current->right; //traverse right
        }
    }
    Frag frag;
    return frag;
}

/**
 * Add a fragrance to some node (recursive)
 *
 * @param node Current node in tree
 * @param frag Fragrance to be added
 */
void BinarySearchTree::addNode(Node* node, Frag frag) {
    // FIXME (8) Implement inserting a frag into the tree
    // if node is less than add to left
    if (node->frag.fragName.compare(frag.fragName) < 0) {
        // if no left node
        if (node->left == nullptr) {
            // this node becomes left
            node->left = new Node(frag); //New node that becomes the root
        }
        // else recurse down the left node
        else {
            this->addNode(node->left, frag); //Add node to the left
        }
    }
    // else
    else {
        // if no right node
        if (node->right == nullptr) {
            // this node becomes right
            node->right = new Node(frag); //New node becomes root
        }
        //else
        else {
            // recurse down the left node
            this->addNode(node->right, frag); //Add node to the right
        }
    }
}
void BinarySearchTree::inOrder(Node* node) {
    // FixMe (9): Pre order root
    //if node is not equal to null ptr
    //InOrder not left
    //output fragBrand, fragName, fragPrice
    //InOder right
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->frag.fragBrand << ": "
            << node->frag.fragName << " | "
            << node->frag.fragPrice << endl;
        inOrder(node->right);
    }
}
void BinarySearchTree::postOrder(Node* node) {
    // FixMe (10): Pre order root
    //if node is not equal to null ptr
    //postOrder left
    //postOrder right
    //output fragBrand, fragName, fragPrice
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->frag.fragBrand << ": "
            << node->frag.fragName << " | "
            << node->frag.fragPrice << endl;
    }
}

void BinarySearchTree::preOrder(Node* node) {
    // FixMe (11): Pre order root
    //if node is not equal to null ptr
    if (node != nullptr) {
        //output fragBrand, fragName, fragPrice
        cout << node->frag.fragBrand << ": "
            << node->frag.fragName << " | "
            << node->frag.fragPrice << endl;
        //postOrder left
        postOrder(node->left);
        //postOrder right      
        postOrder(node->right);
    }
}

