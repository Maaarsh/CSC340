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

void removeHeaderNode(Node *&head)
{
  if (isEmpty(head))
  {
    return; // If the list is empty then there is nothing to remove
  }
  else
  {
    head = head->next; // Set the head to the next node
  }
}

void removeTailNode(Node *&head)
{
  Node *temp = head;
  // If the list is empty then there is nothing to remove
  if (isEmpty(head))
  {
    return;
  }
  // If the list has only one node then delete the node and set the head to nullptr
  else if (head->next == nullptr)
  {
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
    delete temp;
  }
}

void remove(Node *&head, int val) // remove a node with a specific value
{
  Node *temp = head;

  // If the list is empty then there is nothing to remove
  if (isEmpty(head))
  {
    return;
  }
  else
  {
    // If the value is in the head node then remove the head node
    if (head->val == val)
    {
      removeHeaderNode(head);
      return;
    }

    while (temp != nullptr && temp->val != val) // Find the node with the value or the end of the list
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
      removeTailNode(head);
      return;
    }
    // If the value is somewhere in the middle of the list then remove the node
    else
    {
      temp->prev->next = temp->next; // Point the node before temp to the node after temp
      temp->next->prev = temp->prev; // Point the node after temp to the node before temp
      delete temp;
    }
  }
}

void moveNodeToHead(Node *&head, int k)
{
  if (head == nullptr || k < 1 || k == 1)
  {
    return;
  }

  Node *current = head;
  Node *prevKth = nullptr;

  for (int i = 1; current != nullptr && i < k; i++) // for loop until current is null and i is greater k to find the kth node
  {
    prevKth = current;
    current = current->next;
  }

  if (current == nullptr) // If the kth node is not found then return
  {
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

  current->next = head;
  head->prev = current;
  current->prev = nullptr;
  head = current;
}

void moveNodeToTail()
{
}

void clear(Node *&head)
{
  // If the list is empty then there is nothing to clear
  if (isEmpty(head))
  {
    return;
  }
  else
  {
    // Loop through the list and delete each node
    while (head != nullptr)
    {
      removeHeaderNode(head);
    }
  }
}

// REMOVE FUNCTIONS BELOW THIS LINE BEFORE SUBMISSION

void printListForward(Node *&head)
{
  Node *temp = head;
  std::cout << "List after testCase1:" << '\n';
  while (temp != nullptr)
  {
    std::cout << temp->val << " ";
    temp = temp->next;
  }
  std::cout << '\n';
}

void reversePrintList(Node *&head)
{
  Node *temp = head;
  std::cout << "Reverse List after testCase1:" << '\n';
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  while (temp != nullptr)
  {
    std::cout << temp->val << " ";
    temp = temp->prev;
  }
  std::cout << '\n';
}

int main()
{
  Node *head = nullptr;

  std::cout << "Processing testCase1: " << '\n';

  // Check if the list is empty and print a message
  std::cout << "isEmpty: ";
  if (isEmpty(head))
  {
    std::cout << "True" << '\n';
  }
  else
  {
    std::cout << "False" << '\n';
  }

  // Insert val at head and print a message
  std::cout << "Inserted at head: " << insertAtHead(head, 50) << '\n';
  std::cout << "Inserted at head: " << insertAtHead(head, 40) << '\n';
  std::cout << "Inserted at head: " << insertAtHead(head, 30) << '\n';

  // Inserting val at tail and print a message
  std::cout << "Inserted at tail: " << insertAtTail(head, 60) << '\n';
  std::cout << "Inserted at tail: " << insertAtTail(head, 70) << '\n';
  std::cout << "Inserted at tail: " << insertAtTail(head, 80) << '\n';
  std::cout << "Inserted at tail: " << insertAtTail(head, 90) << '\n';

  // Insert val at head and print a message
  std::cout << "Inserted at head: " << insertAtHead(head, 20) << '\n';
  std::cout << "Inserted at head: " << insertAtHead(head, 10) << '\n';

  // Inserting val at tail and print a message
  std::cout << "Inserted at tail: " << insertAtTail(head, 100) << '\n';

  // Check if the list is empty and print a message
  std::cout << "isEmpty: ";
  if (isEmpty(head))
  {
    std::cout << "True" << '\n';
  }
  else
  {
    std::cout << "False" << '\n';
  }

  // Print the list forward
  printListForward(head);

  // Print the list in reverseq
  reversePrintList(head);

  return 0;
}