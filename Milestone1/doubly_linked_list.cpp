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
    head->prev = newNode; // then point the current head (Soon to be old head/second node) back to the new node because doubly linked list goes both ways...
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
  if (prevKth)
  {
    prevKth->next = current->next; // Point the node before the kth node to the node after the kth node
  }
  if (current->next)
  {
    current->next->prev = prevKth;
  }
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

void printListForward(Node *&head)
{
  Node *temp = head;
  std::cout << "List: ";
  while (temp != nullptr)
  {
    std::cout << temp->val << " ";
    temp = temp->next;
  }
  std::cout << '\n';
}

int main()
{
  /* Testing Insertion at Head and Tail */
  Node *head = nullptr;

  // std::cout << "Empty: " << isEmpty(head) << '\n';
  // print isEmpty status
  if (isEmpty(head))
  {
    std::cout << "isEmpty: True" << '\n';
  }
  else
  {
    std::cout << "isEmpty: False" << '\n';
  }
  insertAtHead(head, 1);
  std::cout << "First Inseration at Head: " << head->val << '\n';
  insertAtHead(head, 2);
  std::cout << "Second Inseration at Head: " << head->val << '\n';
  insertAtTail(head, 3);
  std::cout << "First Inseration at Tail: " << head->next->next->val << '\n';
  insertAtTail(head, 4);
  std::cout << "Second Inseration at Tail: " << head->next->next->next->val << '\n';
  remove(head, 3);
  std::cout << "Removed 3" << '\n';
  // print isEmpty status
  if (isEmpty(head))
  {
    std::cout << "isEmpty: True" << '\n';
  }
  else
  {
    std::cout << "isEmpty: False" << '\n';
  }
  printListForward(head);

  // std::cout << "Whole List: " << head->val << " " << head->next->val << " " << head->next->next->val << " " << head->next->next->next->val << '\n';

  /* Testing Removal of Head and Tail */
  removeHeaderNode(head);
  std::cout << "Removed head" << '\n';
  removeTailNode(head);
  std::cout << "Removed tail" << '\n';
  // clear(head);
  printListForward(head);
  // std::cout << "Whole List: " << head->val << " " << head->next->val << '\n';
  // removeTailNode(head);
  // std::cout << "First Removal of Tail: " << head->val << '\n';

  return 0;
}