/*
Milestone 1: Doubly Linked List in C++ Output Generator
By: Marshall Toro

Created with the help of the following resources:
- Github Copilot Visual Studio Code Extension
- https://www.geeksforgeeks.org/doubly-linked-list-in-cpp/
*/

#include <iostream>
#include "doubly_linked_list.cpp"

void printListForward(Node *&head)
{
  Node *temp = head;
  std::cout << "Forward List:" << '\n';
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
  std::cout << "Reverse List:" << '\n';
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

  // Check all functions

  std::cout << "isEmpty: ";
  if (isEmpty(head))
  {
    std::cout << "True" << '\n';
  }
  else
  {
    std::cout << "False" << '\n';
  }

  std::cout << "Inserted at head: " << insertAtHead(head, 50) << '\n';
  std::cout << "Inserted at head: " << insertAtHead(head, 40) << '\n';
  std::cout << "Inserted at head: " << insertAtHead(head, 30) << '\n';

  std::cout << "Inserted at tail: " << insertAtTail(head, 60) << '\n';
  std::cout << "Inserted at tail: " << insertAtTail(head, 70) << '\n';
  std::cout << "Inserted at tail: " << insertAtTail(head, 80) << '\n';
  std::cout << "Inserted at tail: " << insertAtTail(head, 90) << '\n';

  std::cout << "Inserted at head: " << insertAtHead(head, 20) << '\n';
  std::cout << "Inserted at head: " << insertAtHead(head, 10) << '\n';

  std::cout << "Inserted at tail: " << insertAtTail(head, 100) << '\n';

  std::cout << "isEmpty: ";
  if (isEmpty(head))
  {
    std::cout << "True" << '\n';
  }
  else
  {
    std::cout << "False" << '\n';
  }

  printListForward(head);

  reversePrintList(head);

  std::cout << "Removed header node: " << removeHeaderNode(head) << '\n';

  std::cout << "Removed tail node: " << removeTailNode(head) << '\n';

  std::cout << "Removed node with value 50: " << remove(head, 50) << '\n';

  printListForward(head);

  reversePrintList(head);

  std::cout << "Moved 3rd node to the head: " << moveNodeToHead(head, 3) << '\n';

  printListForward(head);

  reversePrintList(head);

  std::cout << "Moved 3rd node to the tail: " << moveNodeToTail(head, 3) << '\n';

  printListForward(head);

  reversePrintList(head);

  clear(head);
  std::cout << "Cleared list" << '\n';

  std::cout << "isEmpty: ";
  if (isEmpty(head))
  {
    std::cout << "True" << '\n';
  }
  else
  {
    std::cout << "False" << '\n';
  }

  return 0;
}