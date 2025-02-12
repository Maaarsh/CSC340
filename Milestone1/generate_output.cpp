/*
Milestone 1: Doubly Linked List in C++ Output Generator
By: Marshall Toro

Created with the help of the following resources:
- Github Copilot Visual Studio Code Extension
- https://www.geeksforgeeks.org/doubly-linked-list-in-cpp/
*/

#include <iostream>
#include "doubly_linked_list.h"
#include "generate_output.h"
#include "dll_node.h"

void printList(DoublyLinkedList &FIFOList)
{
    DllNode *temp = FIFOList.head;
    std::ofstream &outFile = getOutFile(); // Get the reference to the output file stream
    // std::cout << "Forward List:" << '\n';
    // outFile << "Forward List:" << '\n';
    while (temp != nullptr)
    {
        std::cout << temp->key << " ";
        outFile << temp->key << " "; // Write to output file
        temp = temp->next;
    }
    std::cout << '\n';
    outFile << '\n'; // Write a newline to the file
}

void reversePrintList(DoublyLinkedList &FIFOList)
{
    DllNode *temp = FIFOList.head;
    std::ofstream &outFile = getOutFile(); // Get the reference to the output file stream
    // std::cout << "Reverse List:" << '\n';
    // outFile << "Reverse List:" << '\n';
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    while (temp != nullptr)
    {
        std::cout << temp->key << " ";
        outFile << temp->key << " "; // Write to output file
        temp = temp->prev;
    }
    std::cout << '\n';
    outFile << '\n'; // Write a newline to the file
}