/**
Milestone 2: Hash Table in C++
By: Marshall Toro

Created with the help of the following resources:
- Github Copilot Visual Studio Code Extension
*/

/**
 * @file hash_table.cpp
 * @author Marshall Toro (https://maaarsh.github.io/)
 * @brief Hash Table implementation in C++
 * @version 0.1
 * @date 2025-03-05
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include "hash_table.h"

/**
 * @brief Construct a new Hash Table:: Hash Table object
 *
 * @param size
 */
std::ostream *outStream = &std::cout; // Global output stream, default to std::cout

/**
 * @brief Set the Output Stream object
 *
 * @param stream
 */
void setOutputStream(std::ostream &stream)
{
  outStream = &stream;
}

/**
 * @brief Returns a pointer to the hash table's array of buckets
 *
 * @return HashNode**
 */
HashNode **HashTable::getTable()
{
  return table;
}

/**
 * @brief Return the number of buckets in the hash table
 *
 * @return int
 */
int HashTable::getSize()
{
  return numberOfBuckets;
}

/**
 * @brief Calculate the hash code for the current key to be used as an index in the hash table using the modulo operator
 *
 * @param currentKey
 * @return int
 */
int HashTable::calculateHashCode(int currentKey)
{
  return currentKey % numberOfBuckets;
}

/**
 * @brief Checks if the hash table is empty by checking to see if numberOfItems variable is 0
 *
 * @return true
 * @return false
 */
bool HashTable::isEmpty()
{
  return numberOfItems == 0;
}

/**
 * @brief
 *
 * @return int
 */
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
    return true;           /** Return true to indicate success */
  }
  else
  { /** If the index is not empty, add the node to the end of the list */
    while (temp->next != nullptr)
    { /** Traverse the list to the end */
      temp = temp->next;
    }
    temp->next = myNode; /** Add the node to the end of the list */
    numberOfItems++;     /** Increment the number of items */
    return true;         /** Return true to indicate success */
  }
}

bool HashTable::remove(int curKey)
{
  int index = calculateHashCode(curKey); /** Calculate the index for the key */
  HashNode *temp = table[index];         /** Get the node at the index */

  /** If the index is empty, there is nothing to remove */
  if (temp == nullptr)
  {
    return true; /** Return true to indicate success */
  }
  else
  { /** If the index is not empty, remove the node at the end of the list */
    while (temp->next != nullptr)
    { /** Traverse the list to the end */
      temp = temp->next;
    }
    temp->next = nullptr; /** Remove the node at the end of the list */
    numberOfItems--;      /** Decrement the number of items */
    return true;          /** Return true to indicate success */
  }
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
