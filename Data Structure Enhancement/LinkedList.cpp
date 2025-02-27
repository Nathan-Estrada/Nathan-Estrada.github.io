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
 * Append a new bid to the end of the list
 */
void LinkedList::Append(Bid bid) {
    // FIXME (2): Implement append logic
    //Create new node
    Node* newNode = new Node(bid);
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
 * Prepend a new bid to the start of the list
 */
void LinkedList::Prepend(Bid bid) {
    // FIXME (3): Implement prepend logic
    // Create new node
    Node* newNode = new Node(bid);

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
 * Simple output of all bids in the list
 */
void LinkedList::PrintList() {
    // FIXME (4): Implement print logic
    // start at the head
    Node* currNode = head;

    // while loop over each node looking for a match
    while (currNode) {
        //output current bidID, title, amount and fund
        std::cout << currNode->bid.bidId << ":" << currNode->bid.title << " | " << currNode->bid.amount
            << " | " << currNode->bid.fund << endl;
        //set current equal to next
        currNode = currNode->next;
    }
}

/**
 * Remove a specified bid
 *
 * @param bidId The bid id to remove from the list
 */
void LinkedList::Remove(string bidId) {
    // FIXME (5): Implement remove logic
    Node* currNode = head;
    // special case if matching node is the head
    if (currNode && currNode->bid.bidId == bidId) {
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
        // if the next node bidID is equal to the current bidID
        if (currNode->next->bid.bidId == currNode->bid.bidId) {
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
 * Search for the specified bidId
 *
 * @param bidId The bid id to search for
 */
Bid LinkedList::Search(string bidId) {
    // FIXME (6): Implement search logic
    Node* currNode = head;
    // special case if matching node is the head
    // start at the head of the list

    // keep searching until end reached with while loop (current != nullptr)
    while (currNode != nullptr) {
        // if the current node matches, return current bid
        if (bidId == currNode->bid.bidId) {
            return currNode->bid;
        }
        // else current node is equal to next node
        else {
            currNode = currNode->next;
        }
    }
    //(the next two statements will only execute if search item is not found)
      //create new empty bid
     //return empty bid
    return Bid();
}

/**
 * Returns the current size (number of elements) in the list
 */
int LinkedList::Size() {
    return size;
}