/*
Milestone 2: Hash Table in C++
By: Marshall Toro

Created with the help of the following resources:
- Github Copilot Visual Studio Code Extension
*/

#include <iostream>
#include "hash_table.h"

HashNode **HashTable::getTable()
{
  return table;
}

int HashTable::getSize()
{
  return numberOfBuckets;
}

int HashTable::calculateHashCode(int currentKey)
{
  return currentKey % numberOfBuckets;
}

bool HashTable::isEmpty()
{
  return numberOfItems == 0;
}

int HashTable::getNumberOfItems()
{
  return numberOfItems;
}

bool HashTable::add(int curKey, HashNode *myNode)
{
  int index = calculateHashCode(curKey); // Calculate the index for the key
  HashNode *temp = table[index];         // Get the node at the index

  // If the index is empty, add the node
  if (temp == nullptr)
  {
    table[index] = myNode; // Add the node to the table
    numberOfItems++;       // Increment the number of items
    return true;           // Return true to indicate success
  }
  else
  { // If the index is not empty, add the node to the end of the list
    while (temp->next != nullptr)
    { // Traverse the list to the end
      temp = temp->next;
    }
    temp->next = myNode; // Add the node to the end of the list
    numberOfItems++;     // Increment the number of items
    return true;         // Return true to indicate success
  }
}

bool HashTable::remove(int curKey, HashNode *myNode)
{
  int index = calculateHashCode(curKey); // Calculate the index for the key
  HashNode *temp = table[index];         // Get the node at the index

  // If the index is empty, there is nothing to remove
  if (temp == nullptr)
  {
    return true; // Return true to indicate success
  }
  else
  { // If the index is not empty, remove the node at the end of the list
    while (temp->next != nullptr)
    { // Traverse the list to the end
      temp = temp->next;
    }
    temp->next = nullptr; // Remove the node at the end of the list
    numberOfItems--;      // Decrement the number of items
    return true;          // Return true to indicate success
  }
}
