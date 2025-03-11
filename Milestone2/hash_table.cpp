/**
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

/**
 * @brief
 *
 * @return int
 */
int HashTable::getSize()
{
  return numberOfBuckets;
}

int HashTable::calculateHashCode(int currentKey) /** Calculate the hash code for the current key to be used as an index in the hash table */
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
  int index = calculateHashCode(curKey); /** Calculate the index for the key */
  HashNode *temp = table[index];         /** Get the node at the index */

  /** If the index is empty, add the node */
  if (temp == nullptr)
  {
    table[index] = myNode; /** Add the node to the table */
    numberOfItems++;       /** Increment the number of items */
    printTable();
    return true; /** Return true to indicate success */
  }
  else
  { /** If the index is not empty, add the node to the end of the list */
    while (temp->next != nullptr)
    { /** Traverse the list to the end */
      temp = temp->next;
    }
    temp->next = myNode; /** Add the node to the end of the list */
    numberOfItems++;     /** Increment the number of items */
    printTable();
    return true; /** Return true to indicate success */
  }
}

bool HashTable::remove(int curKey)
{
  int index = calculateHashCode(curKey);
  HashNode *temp = table[index];

  // If the bucket is empty, nothing to remove.
  if (temp == nullptr)
  {
    printTable();
    return false;
  }

  // Check if the head node is the one to remove.
  if (temp->key == curKey)
  {
    // Update the bucket pointer to the next node.
    table[index] = temp->next;
    if (temp->next != nullptr)
      temp->next->prev = nullptr;
    delete temp;
    numberOfItems--;
    printTable();
    return true;
  }

  // Traverse the rest of the list.
  while (temp != nullptr)
  {
    std::cout << "Check 1" << std::endl;
    if (temp->key == curKey)
    {
      std::cout << "Check 2" << std::endl;
      // Remove temp from the list.
      std::cout << "Check temp prev" << temp->prev->key << std::endl;
      temp->prev->next = temp->next;
      std::cout << "Check 3" << std::endl;
      if (temp->next != nullptr)
      {
        temp->next->prev = temp->prev;
      }
      std::cout << "Check 4" << std::endl;
      delete temp;
      numberOfItems--;
      printTable();
      return true;
    }
    temp = temp->next;
  }

  printTable();
  return false;
}

void HashTable::clear()
{
  for (int i = 0; i < numberOfBuckets; i++)
  {                            /** Traverse the table */
    HashNode *temp = table[i]; /** Get the node at the index */
    while (temp != nullptr)
    {                              /** Traverse the list */
      HashNode *next = temp->next; /** Get the next node */
      delete temp;                 /** Delete the current node */
      temp = next;                 /** Move to the next node */
    }
    table[i] = nullptr; /** Set the index to null */
  }
  numberOfItems = 0; /** Set the number of items to 0 */
}

HashNode *HashTable::getItem(int curKey)
{
  int index = calculateHashCode(curKey); /** Calculate the index for the key */
  HashNode *temp = table[index];         /** Get the node at the index */

  /** If the index is empty, return null */
  if (temp == nullptr)
  {
    return nullptr; /** Return null to indicate failure */
  }
  else
  {              /** If the index is not empty, return the node at the index */
    return temp; /** Return the node at the index */
  }
}

bool HashTable::contains(int curKey)
{
  int index = calculateHashCode(curKey); /** Calculate the index for the key */
  HashNode *temp = table[index];         /** Get the node at the index */

  /** If the index is empty, return false */
  if (temp == nullptr)
  {
    return false; /** If the index is empty, the key is not in the table */
  }
  else
  { /** If the index is not empty, find the node with the key */
    while (temp != nullptr)
    {
      if (temp->key == curKey)
      {              /** If the key is found, return true */
        return true; /** Return true to indicate success */
      }
      temp = temp->next; /** Move to the next node */
    }
    return false; /** Node not found */
  }
}

void HashTable::printTable()
{
  for (int i = 0; i < numberOfBuckets; i++)
  {                            /** Traverse the table */
    HashNode *temp = table[i]; /** Get the node at the index */
    std::cout << "Index " << i << ": ";
    while (temp != nullptr)
    {                                                                     /** Traverse the list */
      std::cout << "(" << temp->key << ", " << temp->fullName << ") -> "; /** Print the key and value */
      temp = temp->next;                                                  /** Move to the next node */
    }
    std::cout << "nullptr" << std::endl; /** Print null at the end of the list */
  }
}
