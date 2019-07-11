/**************************************************************************/
/* @filename HashTable.h
/* @author Victor Flores 
/* @date 2019/07/11
/* @brief 
/**************************************************************************/

#pragma once

#include "Node.h"

namespace HashTable
{
  /**
  *  Description:
  *     
  *  Sample usage:
  *     
  */
  template <typename K,
            typename V>
  class Table
  {
   public:
    /*********************************************************************************************
    * Constructors
    *********************************************************************************************/
  
    /**
    *  @brief Default constructor
    */
    Table();

    /**
    *  @brief 
    *  @param 
    */
    Table(unsigned int capacity);
    
    /**
    *  @brief Default destructor
    */
    ~Table() = default;
  
    /*********************************************************************************************
    * Methods
    *********************************************************************************************/
  
    /**
    *  @brief  
    *  @param  
    *  @return 
    */
    int
    hashCode(K key);

    /**
    *  @brief 
    *  @param 
    *  @param 
    */
    void
    insertNode(K key, V value);

    /**
    *  @brief  
    *  @param  
    *  @return 
    */
    V
    deleteNode(int key);

    /**
    *  @brief  
    *  @param  
    *  @return 
    */
    V
    get(int key);

    /**
    *  @brief  
    *  @return 
    */
    int
    size();

    /**
    *  @brief  
    *  @return 
    */
    bool
    isEmpty();

    /**
    *  @brief 
    */
    void
    display();
  
    /*********************************************************************************************
    * Members
    *********************************************************************************************/
  
    /**
    *  @brief 
    */
    Vector<Node<K, V>*> m_array;

    /**
    *  @brief 
    */
    int m_capacity;

    /**
    *  @brief 
    */
    int m_size;
  };

  template <typename K,
            typename V>
  void
  HashTable::Table<K, V>::display() {
    //for(int i = 0; i < capacity; i++)
    //{
    //  if(m_array[i] != nullptr && m_array[i]->key != -1)
    //    cout << "key = " << m_array[i]->key
    //    << "  value = " << m_array[i]->value << endl;
    //}
  }

  template <typename K,
            typename V>
  bool
  HashTable::Table<K, V>::isEmpty() {
    return m_size == 0;
  }

  template <typename K,
            typename V>
  int
  HashTable::Table<K, V>::size() {
    return m_size;
  }

  template <typename K,
            typename V>
  V
  HashTable::Table<K, V>::get(int key) {
    int hashIndex = hashCode(key);
    int counter = 0;

    while(m_array[hashIndex] != nullptr)
    {
      int counter = 0;
      if(++counter > m_capacity)
        return static_cast<V>(-1);

      if(m_array[hashIndex]->m_key == key)
        return m_array[hashIndex]->m_value;
      ++hashIndex;
      hashIndex %= m_capacity;
    }

    return static_cast<V>(-1);
  }

  template <typename K,
            typename V>
  V
  HashTable::Table<K, V>::deleteNode(int key) {
    int hashIndex = hashCode(key);

    while(m_array[hashIndex] != nullptr)
    {
      if(m_array[hashIndex]->m_key == key)
      {
        Node<K, V> *temp = m_array[hashIndex];

        m_array[hashIndex] = nullptr;

        --m_size;
        return temp->m_value;
      }
      ++hashIndex;
      hashIndex %= m_capacity;
    }

    return static_cast<V>(-1);
  }

  template <typename K,
            typename V>
  void
  HashTable::Table<K, V>::insertNode(K key, V value) {
    auto* temp = new Node<K, V>(key, value);

    int hashIndex = hashCode(key);

    while(m_array[hashIndex] != nullptr && m_array[hashIndex]->m_key != key
          && m_array[hashIndex]->m_key != -1)
    {
      ++hashIndex;
      hashIndex %= m_capacity;
    }

    if(m_array[hashIndex] == nullptr || m_array[hashIndex]->m_key == -1)
    {
      ++m_size;
    }
    m_array[hashIndex] = temp;
  }

  template <typename K,
            typename V>
  int
  HashTable::Table<K, V>::hashCode(K key) {
    return key % m_capacity;
  }

  template <typename K,
            typename V>
  HashTable::Table<K, V>::Table(unsigned int capacity) : m_capacity(capacity),
                                    m_size(0) {
    m_array.resize(m_capacity);
  }

  template <typename K,
            typename V>
  HashTable::Table<K, V>::Table() : m_capacity(20),
                                    m_size(0) {
    m_array.resize(m_capacity);

  }
}
