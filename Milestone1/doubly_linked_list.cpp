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

void remove(Node *&head, int val)
{
  Node *newNode = head;

  if (isEmpty(head))
  {
    return;
  }
  // else if ()
  // {
  // }
}

void removeHeaderNode(Node *&head)
{
  Node *temp = head;
  // If the list is empty then there is nothing to remove
  if (isEmpty(head))
  {
    return;
  } /*
   // If the list has only one node then delete the node and set the head to nullptr
    else if (head->next == nullptr)
    {
      delete head;
      head = nullptr;
    }
   // If the list has more than one node then delete the head node and set the next node as the head
    else
    {
      delete head;
      head = temp->next;
      head->prev = nullptr;
    }*/
  head = head->next;   // Wanted to call this temp2 (Like this, "Node *temp2 = head->next") for readability but it was messing up the output. I don't know why.
  if (head != nullptr) // If the next node (after the first one) is not null (AKA there is more than 1 node) then set the previous node (the first node) to null
  {
    head->prev = nullptr;
  }
  delete temp; // Delete the first node regardless of the number of nodes
}

void removeTailNode(Node *&head) // DOES NOT WORK! COME BACK TO THIS!
{
  Node *temp = head;
  if (isEmpty(head))
  {
    return;
  }
  else if (head->next == nullptr)
  {
    delete head;
    head = nullptr;
    return;
  }
  else
  {
    while (temp->next->next != nullptr)
    {
      temp = temp->next;
    }

    Node *tail = temp->next;
    temp->next = nullptr;
    delete tail;
  }
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
  /* Testing Insertion at Head and Tail */
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

  /* Testing Removal of Head and Tail */
  removeHeaderNode(head);
  // std::cout << "First Removal of Head: " << head->val << '\n';
  std::cout << "Whole List: " << head->val << " " << head->next->val << " " << head->next->next->val << '\n';
  // removeTailNode(head);
  //  std::cout << "First Removal of Tail: " << head->val << '\n';

  return 0;
}