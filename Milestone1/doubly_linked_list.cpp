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
DoublyLinkedList::~DoublyLinkedList()
{
  clear();
}

// replace Node with DllNode

bool DoublyLinkedList::isEmpty() // needs to empty in ()
{
  if (head == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void DoublyLinkedList::insertAtHead(int key) // int key parameter only
{
  DllNode *newDllNode = new DllNode(key); // Create a new node with the given value

  if (isEmpty()) // If the list is empty then the new node is the head
  {
    head = newDllNode;
    return;
  }
  else // Not needed but I like it for readability
  {
    // Inserting at head so we put the new node at the front of the list so...
    newDllNode->next = head; // point the new node to the current head (Soon to be old head/second node)...
    head->prev = newDllNode; // then point the current head (Soon to be old head/second node) back to the new node because doubly linked list goes both ways...
    head = newDllNode;       // then set the new node as the head.
    return;
  }
}

void DoublyLinkedList::insertAtTail(int key)
{
  DllNode *newDllNode = new DllNode(key); // Create a new node with the given value.

  if (isEmpty())
  {
    head = newDllNode;
    return;
  }
  else
  {
    // Find the last node in the list
    DllNode *temp = head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }

    // Insert the new node at the end of the list
    // temp->next = newNode; // Point the last node to the new node. DONT NEED THIS NEW NODE
    newDllNode->prev = temp; // Point the new node back to the last node
    return;
  }
}

void DoublyLinkedList::removeHeaderNode()
{
  if (isEmpty())
  {
    std::cout << "List is empty" << '\n';
    return; // If the list is empty then there is nothing to remove
  }
  else
  {
    DllNode *temp = head; // Create a temporary node to store the head
    head = head->next;    // Set the head to the next node
    head->prev = nullptr; // Set previous node of the new head to null
    return;
  }
}

void DoublyLinkedList::removeTailNode()
{
  DllNode *temp = head;
  // If the list is empty then there is nothing to remove
  if (isEmpty())
  {
    std::cout << "List is empty" << '\n';
    return;
  }
  // If the list has only one node then delete the node and set the head to nullptr
  else if (head->next == nullptr)
  {
    DllNode *temp = head;
    head = nullptr;
    delete head;
    return;
  }
  else
  {
    // Find the second to last node in the list
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->prev->next = nullptr; // Point the second to last node to null
    int key = temp->key;
    delete temp;
    return;
  }
}

void DoublyLinkedList::remove(int key) // remove a node with a specific value
{
  DllNode *temp = head;

  // If the list is empty then there is nothing to remove
  if (isEmpty())
  {
    std::cout << "List is empty" << '\n';
    return;
  }
  else
  {
    // If the value is in the head node then remove the head node
    if (head->key == key)
    {
      removeHeaderNode();
      return;
    }

    while (temp != nullptr && temp->key != key) // Find the node with the value or the end of the list
    {
      temp = temp->next;
    }

    // If the value is not found then print a message
    if (temp == nullptr)
    {
      std::cout << "Value not found" << '\n';
      return;
    }
    // If the value is in the last node then remove the last node
    else if (temp->next == nullptr)
    {
      removeTailNode();
      return;
    }
    // If the value is somewhere in the middle of the list then remove the node
    else
    {
      // Node *temp2 = temp;
      temp->prev->next = temp->next; // Point the node before temp to the node after temp
      temp->next->prev = temp->prev; // Point the node after temp to the node before temp
      delete temp;
      return;
    }
  }
}

void DoublyLinkedList::moveNodeToHead(int key)
{
  // If the list is empty then there is nothing to move or if k is less than 1 it is an invalid input or if k is 1 then the node is already at the head
  if (head == nullptr || key < 1 || key == 1)
  {
    std::cout << "Invalid input or list is empty" << '\n';
    return;
  }

  DllNode *current = head;
  DllNode *prevKth = nullptr;

  for (int i = 1; current != nullptr && i < key; i++) // for loop until current is not null and i is greater than k to find the kth node
  {
    prevKth = current;
    current = current->next;
  }

  if (current == nullptr) // If the kth node is not found then return
  {
    std::cout << "Node not found" << '\n';
    return;
  }
  if (prevKth != nullptr) // If the kth node is not the head node then...
  {
    prevKth->next = current->next; // ...point the node before the kth node to the node after the kth node
  }
  if (current->next != nullptr) // If the kth node is not the last node then...
  {
    current->next->prev = prevKth; // ...point the node after the kth node to the node before the kth node
  }

  current->next = head;    // Make the current node point to the head
  head->prev = current;    // Make the head point to the current node
  current->prev = nullptr; // Make the current node point to null
  head = current;          // Make the current node the head
  return;
}

void DoublyLinkedList::moveNodeToTail(int key)
{
  // If the list is empty then there is nothing to move or if k is less than 1 it is an invalid input
  if (head == nullptr || key < 1)
  {
    std::cout << "Invalid input or list is empty" << '\n';
    return;
  }

  DllNode *current = head;
  DllNode *prevKth = nullptr;

  for (int i = 1; current != nullptr && i < key; i++) // for loop until current is not null and i is greater than k to find the kth node
  {
    prevKth = current;
    current = current->next;
  }

  if (current == nullptr) // If the kth node is not found then return
  {
    std::cout << "Node not found" << '\n';
    return;
  }
  if (prevKth != nullptr) // If the kth node is not the head node then...
  {
    prevKth->next = current->next; // ...point the node before the kth node to the node after the kth node
  }
  if (current->next != nullptr) // If the kth node is not the last node then...
  {
    current->next->prev = prevKth; // ...point the node after the kth node to the node before the kth node
  }

  insertAtTail(current->key); // Insert the kth node at the tail
  return;
}

void DoublyLinkedList::clear()
{
  // If the list is empty then there is nothing to clear
  if (isEmpty())
  {
    std::cout << "List is empty" << '\n';
    return;
  }
  else
  {
    // Loop through the list and delete each node
    while (head != nullptr)
    {
      DllNode *temp = head;
      head = head->next;
      delete temp;
    }
  }
}