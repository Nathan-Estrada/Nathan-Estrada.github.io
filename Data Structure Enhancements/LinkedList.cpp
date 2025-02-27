#include "LinkedList.hpp"
#include <iostream>

/**
 * Default constructor
 */
LinkedList::LinkedList() {
    // FIXME (1): Initialize housekeeping variables
    //set head and tail equal to nullptr
    head = nullptr;
    tail = nullptr;
}

/**
 * Destructor
 */
LinkedList::~LinkedList() {
    // start at the head
    Node* current = head;
    Node* temp;

    // loop over each node, detach from list then delete
    while (current != nullptr) {
        temp = current; // hang on to current node
        current = current->next; // make current the next node
        delete temp; // delete the previous node
    }
}

/**
 * Append a new fragrance to the end of the list
 */
void LinkedList::Append(Frag frag) {
    // FIXME (2): Implement append logic
    //Create new node
    Node* newNode = new Node(frag);
    //if there is nothing at the head...
    if (nullptr == head) {
        // new node becomes the head and the tail
        head = tail = newNode;
    }
    //else
    else {
        // make current tail node point to the new node
        tail->next = newNode;
        // and tail becomes the new node
        tail = newNode;
    }
    //increase size count
    size += 1;
}

/**
 * Prepend a new fragrance to the start of the list
 */
void LinkedList::Prepend(Frag frag) {
    // FIXME (3): Implement prepend logic
    // Create new node
    Node* newNode = new Node(frag);

    // if there is already something at the head...
    if (nullptr != head) {
        // new node points to current head as its next node
        newNode->next = head;
        // head now becomes the new node
        head = newNode;
    }
    //increase size count
    size += 1;
}

/**
 * Simple output of all fragrances in the list
 */
void LinkedList::PrintList() {
    // FIXME (4): Implement print logic
    // start at the head
    Node* currNode = head;

    // while loop over each node looking for a match
    while (currNode) {
        //output current fragBrand, fragName, and fragPrice
        std::cout << currNode->frag.fragBrand << ":" << currNode->frag.fragName << " | " << currNode->frag.fragPrice<<endl;
        //set current equal to next
        currNode = currNode->next;
    }
}

/**
 * Remove a specified fragrance
 *
 */
void LinkedList::Remove(string fragName) {
    // FIXME (5): Implement remove logic
    Node* currNode = head;
    // special case if matching node is the head
    if (currNode && currNode->frag.fragName == fragName) {
        // make head point to the next node in the list
        head = currNode->next;
        //decrease size count
        delete currNode; //Delete specified node
        size -= 1;
        //return
        return;
    }

    // start at the head
    // while loop over each node looking for a match
    while (currNode->next) {
        // if the next node fragName is equal to the current fragName
        if (currNode->next->frag.fragName == currNode->frag.fragName) {
            // hold onto the next node temporarily
            Node* temp = currNode->next; //Create temporary variable
            // make current node point beyond the next node
            currNode->next = currNode->next->next; //Because next node gets deleted, current nodes pointer points to two nodes from current node
            // now free up memory held by temp
            delete temp;
            // decrease size count
            size -= 1;
            //return
            return;
        }
    }
    // curretn node is equal to next node
    currNode = currNode->next;
}

/**
 * Search for the specified fragName
 */
Frag LinkedList::Search(string fragName) {
    // FIXME (6): Implement search logic
    Node* currNode = head;
    // special case if matching node is the head
    // start at the head of the list

    // keep searching until end reached with while loop (current != nullptr)
    while (currNode != nullptr) {
        // if the current node matches, return current fragrance
        if (fragName == currNode->frag.fragName) {
            return currNode->frag;
        }
        // else current node is equal to next node
        else {
            currNode = currNode->next;
        }
    }
    //(the next two statements will only execute if search item is not found)
      //create new empty fragrance
     //return empty fragrance
    return Frag();
}

/**
 * Returns the current size (number of elements) in the list
 */
int LinkedList::Size() {
    return size;
}