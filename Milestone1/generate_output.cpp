/*
Milestone 1: Doubly Linked List in C++ Output Generator
By: Marshall Toro

Created with the help of the following resources:
- Github Copilot Visual Studio Code Extension
- https://www.geeksforgeeks.org/doubly-linked-list-in-cpp/
*/

#include <iostream>

class Node
{
public:
  int val;
  Node *next;
  Node *prev;

  Node(int val)
  {
    this->val = val;
    this->next = nullptr;
    this->prev = nullptr;
  };
};

void printList(Node *&head)
{
  Node *temp = head;
  std::cout << "List after testCase1: ";
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
  std::cout << "Reverse List after testCase1: ";
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