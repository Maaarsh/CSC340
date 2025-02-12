/*
Milestone 1: Doubly Linked List in C++
By: Marshall Toro

Created with the help of the following resources:
- Github Copilot Visual Studio Code Extension
- https://www.geeksforgeeks.org/doubly-linked-list-in-cpp/
- https://www.geeksforgeeks.org/move-the-kth-element-to-the-front-of-a-doubly-linked-list/
*/

#include <iostream>
#include "doubly_linked_list.h"

// Constructor: Initializes the list to be empty
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// Destructor: Clears the list
DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

// Method to check if the list is empty
bool DoublyLinkedList::isEmpty() {
    return head == nullptr;
}

// Method to insert a new node at the head of the list
void DoublyLinkedList::insertAtHead(int key) {
    DllNode* newDllNode = new DllNode(key); // Create a new node with the given value

    if (isEmpty()) { // If the list is empty then the new node is the head
        head = tail = newDllNode;
    } else {
        newDllNode->next = head; // Point the new node to the current head
        head->prev = newDllNode; // Point the current head back to the new node
        head = newDllNode;       // Set the new node as the head
    }
}

// Method to insert a new node at the tail of the list
void DoublyLinkedList::insertAtTail(int key) {
    DllNode* newDllNode = new DllNode(key); // Create a new node with the given value

    if (isEmpty()) {
        head = tail = newDllNode;
    } else {
        tail->next = newDllNode; // Point the current tail to the new node
        newDllNode->prev = tail; // Point the new node back to the current tail
        tail = newDllNode;       // Set the new node as the tail
    }
}

// Method to remove the header node (first node)
void DoublyLinkedList::removeHeaderNode() {
    if (isEmpty()) {
        std::cout << "List is empty" << '\n';
        return;
    } else {
        DllNode* temp = head; // Create a temporary node to store the head
        head = head->next;    // Set the head to the next node
        if (head != nullptr) {
            head->prev = nullptr; // Set previous node of the new head to null
        } else {
            tail = nullptr; // If the list is now empty, set tail to nullptr
        }
        delete temp;
    }
}

// Method to remove the tail node (last node)
void DoublyLinkedList::removeTailNode() {
    if (isEmpty()) {
        std::cout << "List is empty" << '\n';
        return;
    } else if (head->next == nullptr) { // If the list has only one node
        delete head;
        head = tail = nullptr;
    } else {
        DllNode* temp = tail; // Create a temporary node to store the tail
        tail = tail->prev;    // Set the tail to the previous node
        tail->next = nullptr; // Set next node of the new tail to null
        delete temp;
    }
}

// Method to remove a node with a specific value from the list
void DoublyLinkedList::remove(int key) {
    if (isEmpty()) {
        std::cout << "List is empty" << '\n';
        return;
    } else {
        DllNode* temp = head;
        while (temp != nullptr && temp->key != key) { // Find the node with the value or the end of the list
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Value not found" << '\n';
            return;
        } else if (temp == head) {
            removeHeaderNode();
        } else if (temp == tail) {
            removeTailNode();
        } else {
            temp->prev->next = temp->next; // Point the node before temp to the node after temp
            temp->next->prev = temp->prev; // Point the node after temp to the node before temp
            delete temp;
        }
    }
}

// Method to move a specific node to the head of the list
void DoublyLinkedList::moveNodeToHead(int key) {
    if (head == nullptr || key < 1) {
        std::cout << "Invalid input or list is empty" << '\n';
        return;
    }

    DllNode* current = head;
    DllNode* prevKth = nullptr;

    while (current != nullptr && current->key != key) {
        prevKth = current;
        current = current->next;
    }

    if (current == nullptr) {
        std::cout << "Node not found" << '\n';
        return;
    }

    if (current == head) {
        return; // Node is already at the head
    }

    if (prevKth != nullptr) {
        prevKth->next = current->next; // Point the node before the kth node to the node after the kth node
    }
    if (current->next != nullptr) {
        current->next->prev = prevKth; // Point the node after the kth node to the node before the kth node
    }

    current->next = head;    // Make the current node point to the head
    head->prev = current;    // Make the head point to the current node
    current->prev = nullptr; // Make the current node point to null
    head = current;          // Make the current node the head
}

// Method to move a specific node to the tail of the list
void DoublyLinkedList::moveNodeToTail(int key) {
    if (head == nullptr || key < 1) {
        std::cout << "Invalid input or list is empty" << '\n';
        return;
    }

    DllNode* current = head;
    DllNode* prevKth = nullptr;

    while (current != nullptr && current->key != key) {
        prevKth = current;
        current = current->next;
    }

    if (current == nullptr) {
        std::cout << "Node not found" << '\n';
        return;
    }

    if (current == tail) {
        return; // Node is already at the tail
    }

    if (prevKth != nullptr) {
        prevKth->next = current->next; // Point the node before the kth node to the node after the kth node
    }
    if (current->next != nullptr) {
        current->next->prev = prevKth; // Point the node after the kth node to the node before the kth node
    }

    current->next = nullptr;
    current->prev = tail;
    tail->next = current;
    tail = current;
}

// Method to clear the list by deleting all nodes
void DoublyLinkedList::clear() {
    while (head != nullptr) {
        DllNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}