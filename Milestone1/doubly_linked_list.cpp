/*
Milestone 1: Doubly Linked List in C++
By: Marshall Toro

Created with the help of the following resources:
- Github Copilot Visual Studio Code Extension
- https://www.geeksforgeeks.org/doubly-linked-list-in-cpp/
- https://www.geeksforgeeks.org/move-the-kth-element-to-the-front-of-a-doubly-linked-list/
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

bool isEmpty(Node *&head) // Maybe come back to this to print out a message
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

int insertAtHead(Node *&head, int val)
{
  Node *newNode = new Node(val); // Create a new node with the given value

  if (isEmpty(head)) // If the list is empty then the new node is the head
  {
    head = newNode;
    return val;
  }
  else // Not needed but I like it for readability
  {
    // Inserting at head so we put the new node at the front of the list so...
    newNode->next = head; // point the new node to the current head (Soon to be old head/second node)...
    head->prev = newNode; // then point the current head (Soon to be old head/second node) back to the new node because doubly linked list goes both ways...
    head = newNode;       // then set the new node as the head.
    return val;
  }
}

int insertAtTail(Node *&head, int val)
{
  Node *newNode = new Node(val); // Create a new node with the given value

  if (isEmpty(head))
  {
    head = newNode;
    return val;
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
    return val;
  }
}

int removeHeaderNode(Node *&head)
{
  if (isEmpty(head))
  {
    std::cout << "List is empty" << '\n';
    return -1; // If the list is empty then there is nothing to remove
  }
  else
  {
    Node *temp = head;    // Create a temporary node to store the head
    head = head->next;    // Set the head to the next node
    head->prev = nullptr; // Set previous node of the new head to null
    return temp->val;
  }
}

int removeTailNode(Node *&head)
{
  Node *temp = head;
  // If the list is empty then there is nothing to remove
  if (isEmpty(head))
  {
    std::cout << "List is empty" << '\n';
    return -1;
  }
  // If the list has only one node then delete the node and set the head to nullptr
  else if (head->next == nullptr)
  {
    Node *temp = head;
    head = nullptr;
    delete head;
    return temp->val;
  }
  else
  {
    // Find the second to last node in the list
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->prev->next = nullptr; // Point the second to last node to null
    int val = temp->val;
    delete temp;
    return val;
  }
}

int remove(Node *&head, int val) // remove a node with a specific value
{
  Node *temp = head;

  // If the list is empty then there is nothing to remove
  if (isEmpty(head))
  {
    std::cout << "List is empty" << '\n';
    return -1;
  }
  else
  {
    // If the value is in the head node then remove the head node
    if (head->val == val)
    {
      removeHeaderNode(head);
      return -1;
    }

    while (temp != nullptr && temp->val != val) // Find the node with the value or the end of the list
    {
      temp = temp->next;
    }

    // If the value is not found then print a message
    if (temp == nullptr)
    {
      std::cout << "Value not found" << '\n';
      return -1;
    }
    // If the value is in the last node then remove the last node
    else if (temp->next == nullptr)
    {
      removeTailNode(head);
      return -1;
    }
    // If the value is somewhere in the middle of the list then remove the node
    else
    {
      // Node *temp2 = temp;
      temp->prev->next = temp->next; // Point the node before temp to the node after temp
      temp->next->prev = temp->prev; // Point the node after temp to the node before temp
      delete temp;
      return val;
    }
  }
}

int moveNodeToHead(Node *&head, int k)
{
  // If the list is empty then there is nothing to move or if k is less than 1 it is an invalid input or if k is 1 then the node is already at the head
  if (head == nullptr || k < 1 || k == 1)
  {
    std::cout << "Invalid input or list is empty" << '\n';
    return -1;
  }

  Node *current = head;
  Node *prevKth = nullptr;

  for (int i = 1; current != nullptr && i < k; i++) // for loop until current is not null and i is greater than k to find the kth node
  {
    prevKth = current;
    current = current->next;
  }

  if (current == nullptr) // If the kth node is not found then return
  {
    std::cout << "Node not found" << '\n';
    return -1;
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
  return current->val;
}

int moveNodeToTail(Node *&head, int k)
{
  // If the list is empty then there is nothing to move or if k is less than 1 it is an invalid input
  if (head == nullptr || k < 1)
  {
    std::cout << "Invalid input or list is empty" << '\n';
    return -1;
  }

  Node *current = head;
  Node *prevKth = nullptr;

  for (int i = 1; current != nullptr && i < k; i++) // for loop until current is not null and i is greater than k to find the kth node
  {
    prevKth = current;
    current = current->next;
  }

  if (current == nullptr) // If the kth node is not found then return
  {
    std::cout << "Node not found" << '\n';
    return -1;
  }
  if (prevKth != nullptr) // If the kth node is not the head node then...
  {
    prevKth->next = current->next; // ...point the node before the kth node to the node after the kth node
  }
  if (current->next != nullptr) // If the kth node is not the last node then...
  {
    current->next->prev = prevKth; // ...point the node after the kth node to the node before the kth node
  }

  insertAtTail(head, current->val); // Insert the kth node at the tail
  return current->val;
}

void clear(Node *&head)
{
  // If the list is empty then there is nothing to clear
  if (isEmpty(head))
  {
    std::cout << "List is empty" << '\n';
    return;
  }
  else
  {
    // Loop through the list and delete each node
    while (head != nullptr)
    {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }
}