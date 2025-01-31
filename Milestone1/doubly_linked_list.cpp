/*
Milestone 1: Doubly Linked List in C++
By: Marshall Toro

Created with the help of the following resources:
Github Copilot Visual Studio Code Extension
https://www.geeksforgeeks.org/doubly-linked-list-in-cpp/
*/

#include <iostream>

class Node
{
public:
  int val;
  Node *next; // Pointer to the next node
  Node *prev; // Pointer to the previous

  // Intialize the node with the data yet to be given
  Node(int val)
  {
    this->val = val;
    this->next = nullptr;
    this->prev = nullptr;
  };
};

bool isEmpty(Node *&head) // Mayvbe come back to this to print out a message
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

void insertAtHead(Node *&head, int val)
{
  Node *newNode = new Node(val); // Create a new node with the given value

  if (isEmpty(head)) // If the list is empty then the new node is the head
  {
    head = newNode;
    return;
  }
  else // Not needed but I like it for readability
  {
    // Inserting at head so we put the new node at the front of the list so...
    newNode->next = head; // point the new node to the current head (Soon to be old head/second node)...
    head->prev = newNode; // then point the current head (Soon to be old head/second nod) back to the new node because doubly linked list goes both ways...
    head = newNode;       // then set the new node as the head.
  }
}

void insertAtTail(Node *&head, int val)
{
  Node *newNode = new Node(val); // Create a new node with the given value

  if (isEmpty(head))
  {
    head = newNode;
    return;
  }
  else
  {
    // Find the last node in the list
    Node *temp = head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }

    // Insert the new node at the end of the list
    temp->next = newNode; // Point the last node to the new node
    newNode->prev = temp; // Point the new node back to the last node
  }
}

void remove()
{
}

void removeHeaderNode()
{
}

void removeTailNode()
{
}

void moveNodeToHead()
{
}

void moveNodeToTail()
{
}

void clear()
{
}

int main()
{
  /* Testing Insertion at Head and Tail
  Node *head = nullptr;

  std::cout << "Empty: " << isEmpty(head) << '\n';
  insertAtHead(head, 1);
  std::cout << "First Inseration at Head: " << head->val << '\n';
  insertAtHead(head, 2);
  std::cout << "Second Inseration at Head: " << head->val << '\n';
  insertAtTail(head, 3);
  std::cout << "First Inseration at Tail: " << head->next->next->val << '\n';
  insertAtTail(head, 4);
  std::cout << "Second Inseration at Tail: " << head->next->next->next->val << '\n';

  std::cout << "Whole List: " << head->val << " " << head->next->val << " " << head->next->next->val << " " << head->next->next->next->val << '\n';
  */

  return 0;
}