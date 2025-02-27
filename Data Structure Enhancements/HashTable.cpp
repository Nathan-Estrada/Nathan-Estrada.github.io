#include "HashTable.hpp"
#include <iostream>

/**
 * Default constructor
 */
HashTable::HashTable() {
    // FIXME (1): Initialize the structures used to hold fragrances
    nodes.resize(tableSize);

    // Initalize node structure by resizing tableSize
}

/**
 * Constructor for specifying size of the table
 * Use to improve efficiency of hashing algorithm
 * by reducing collisions without wasting memory.
 */
HashTable::HashTable(unsigned int size) {
    // invoke local tableSize to size with this->
    this->tableSize = size;
    // resize nodes size
    nodes.resize(size);
}


/**
 * Destructor
 */
HashTable::~HashTable() {
    // FIXME (2): Implement logic to free storage when class is destroyed    

    // erase nodes beginning
    nodes.erase(nodes.begin());
}

/**
 * Calculate the hash value of a given key.
 * Note that key is specifically defined as
 * unsigned int to prevent undefined results
 * of a negative list index.
 *
 * @param key The key to hash
 * @return The calculated hash
 */
unsigned int HashTable::hash(int key) {
    // FIXME (3): Implement logic to calculate a hash value
    // return key tableSize
    return key % tableSize; //If number of fragrances is less than size of hash table, each fragrance will have its own data slot
    //If the number of fragrances is greater than table size, fragrances will have a chance to be as distributed as possible
}

/**
 * Insert a fragrance
 *
 * @param frag The frag to insert
 */
void HashTable::Insert(Frag frag) {
    // FIXME (5): Implement logic to insert a fragrance
    // create the key for the given fragrance
    unsigned key = hash(atoi(frag.fragName.c_str())); //Convert frag name string to integer and assign to key
    // retrieve node using key
    Node* oldNode = &(nodes.at(key));
    // if no entry found for the key
    if (oldNode == nullptr) {
        // assign this node to the key position
        Node* newNode = new Node(frag, key);
        nodes.insert(nodes.begin() + key, (*newNode));
    }
    // else if node is not used
    else {
        if (oldNode->key == UINT_MAX) {
            // assing old node key to UNIT_MAX, set to key, set old node to frag and old node next to null pointer
            oldNode->key = key;
            oldNode->frag = frag;
            oldNode->next = nullptr;
        }
        else {
            //Collision detected
            //Find next open node
            while (oldNode->next != nullptr) {
                oldNode = oldNode->next;
            }
            oldNode->next = new Node(frag, key);
        }

    }
    // else find the next open node

        // add new newNode to end
        //Collision detected
        //Find next open slot


}

/**
 * Print all fragrances
 */
void HashTable::PrintAll() {
    // FIXME (6): Implement logic to print all fragrances
    // for node begin to end iterate
    for (auto i = nodes.begin(); i != nodes.end(); i++) {
        //   if key not equal to UINT_MAx
        if (i->key != UINT_MAX) {
            // output key, fragBrand, name, price
            cout << "Key:" << i->key << ": " << i->frag.fragBrand << " | " << i->frag.fragName << " | "
                << i->frag.fragPrice << endl;
            // node is equal to next iter
            Node* node = i->next;
            // while node not equal to nullptr
            while (node != nullptr) {
                // output key, fragBrand, name, price
                cout << "Key:" << i->key << ": " << i->frag.fragBrand << " | " << i->frag.fragName << " | "
                    << i->frag.fragPrice << endl;
                // node is equal to next node
                node = node->next;
            }
        }
    }

}

/**
 * Remove a fragrance
 *
 */
void HashTable::Remove(string fragName) {
    // FIXME (7): Implement logic to remove a fragrance
    // set key equal to hash atoi frag cstring
    unsigned int key = hash(atoi(fragName.c_str())); //Convert fragName string to int and assing to key
    // erase node begin and key
    Node* node = &(nodes.at(key));
    if (node->key != UINT_MAX) {
        //If nodes match
        if (node->frag.fragName.compare(fragName) == 0) {
            //remove this node
            cout << "Remove top nodes for " << fragName << endl;
            //Remove node
            if (node->next == nullptr) {
                node->key = UINT_MAX;
                return;
            }
            else {
                nodes.at(key) = *(node->next);
                return;
            }
        }
        else {
            Node* cur = node->next;
            Node* pre = node;
            while (cur != nullptr) {
                if (cur->frag.fragName.compare(fragName) == 0) {
                    //delete this node
                    pre->next == cur->next; //Skips node that will be deleted
                    delete cur;
                    cur = nullptr;
                    return;
                }
                pre = cur;
                cur = cur->next;
            }
        }
    }
}

/**
 * Search for the specified fragrance name
 *
 */
Frag HashTable::Search(string fragName) {
    Frag frag;

    // FIXME (8): Implement logic to search for and return a fragrance

    // create the key for the given fragrance
    unsigned int key = hash(atoi(fragName.c_str()));//Convert frag id string to int and assign to key
    Node* node = &(nodes.at(key));//Assign node to node at calculated key

    // if entry found for the key
    if (node != nullptr && node->key != UINT_MAX && node->frag.fragName.compare(fragName) == 0) {
        //return node frag
        return node->frag;
    }

    // if no entry found for the key
    if (node == nullptr || node->key == UINT_MAX) {
        // return frag
        return frag;
    }
    // while node not equal to nullptr
    while (node != nullptr) {
        // if the current node matches, return it
        if (node->key != UINT_MAX && node->frag.fragName.compare(fragName) == 0) {
            //node is equal to next node
            node = node->next;
        }
    }

    return frag;
}
