/**
Milestone 2: Hash Table in C++
By: Marshall Toro

Created with the help of the following resources:
- Github Copilot Visual Studio Code Extension
*/

#include <iostream>
#include "hash_table.h"

/**
 * @brief Provides access to the hash table to allow for the code to interact with the hash table and its nodes
 *
 * @return HashNode**
 */
HashNode **HashTable::getTable()
{
  return table;
}

/**
 * @brief Get the number of buckets in the hash table to be used to calculate the index for the key
 *
 * @return int
 */
int HashTable::getSize()
{
  return numberOfBuckets;
}

/**
 * @brief Calculate the hash code for the current key to be used as an index in the hash table
 *
 * @param currentKey
 * @return int
 */
int HashTable::calculateHashCode(int currentKey)
{
  return currentKey % numberOfBuckets;
}

/**
 * @brief Check if the hash table is empty by checking if the number of items is 0
 *
 * @return true
 * @return false
 */
bool HashTable::isEmpty()
{
  return numberOfItems == 0;
}

/**
 * @brief Get the number of items in the hash table to be used to check if the table is empty
 *
 * @return int
 */
int HashTable::getNumberOfItems()
{
  return numberOfItems;
}

/**
 * @brief Add a new node to the hash table by calculating the index for the key and adding the node to the end of the list at that index
 *
 * @param curKey
 * @param myNode
 * @return true
 * @return false
 */
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
    myNode->prev = temp; /** Set the previous pointer of the new node to the last node */
    numberOfItems++;     /** Increment the number of items */
    return true;         /** Return true to indicate success */
  }
}

/**
 * @brief Remove a node from the hash table by calculating the index for the key and removing the node from the list at that index
 *
 * @param curKey
 * @return true
 * @return false
 */
bool HashTable::remove(int curKey)
{
  int index = calculateHashCode(curKey);
  HashNode *temp = table[index];

  /** If the bucket is empty, nothing to remove */
  if (temp == nullptr)
  {
    return false;
  }

  /** Check if the head node is the one to remove */
  if (temp->key == curKey)
  {
    /** Update the bucket pointer to the next node */
    table[index] = temp->next;
    if (temp->next != nullptr)
      temp->next->prev = nullptr;
    delete temp;
    numberOfItems--;
    return true;
  }

  /** Traverse the rest of the list */
  while (temp != nullptr)
  {
    if (temp->key == curKey)
    {
      /** Remove temp from the list */
      temp->prev->next = temp->next;
      if (temp->next != nullptr)
      {
        temp->next->prev = temp->prev;
      }
      delete temp;
      numberOfItems--;
      return true;
    }
    temp = temp->next;
  }
  return false;
}

/**
 * @brief Clear the hash table by deleting all the nodes in the table and setting the number of items to 0
 *
 */
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

/**
 * @brief Get the item at the current key by calculating the index for the key and returning the node at that index
 *
 * @param curKey
 * @return HashNode*
 */
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

/**
 * @brief Check if the hash table contains the current key by calculating the index for the key and checking if the node at that index is not null and has the same key
 *
 * @param curKey
 * @return true
 * @return false
 */
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

/**
 * @brief Print the hash table by traversing the table and printing the key and value of each node in the list at each index
 *
 */
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