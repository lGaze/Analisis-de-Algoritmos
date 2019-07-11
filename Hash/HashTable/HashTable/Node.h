/**************************************************************************/
/* @filename Node.h
/* @author Victor Flores 
/* @date 2019/07/11
/* @brief 
/**************************************************************************/

#pragma once

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
  struct Node
  {
   public:
    /*********************************************************************************************
    * Constructors
    *********************************************************************************************/
  
    /**
    *  @brief Default constructor
    */
    Node() = default;
    
    /**
    *  @brief Constructor with parameters
    *  @param key for this value
    *  @param actual value in the bucket
    */
    Node(K key, V value) : m_key(key),
                           m_value(value) {}

    /**
    *  @brief Default destructor
    */
    ~Node() = default;
  
    /*********************************************************************************************
    * Members
    *********************************************************************************************/
  
    /**
    *  @brief 
    */
    K m_key;

    /**
    *  @brief 
    */
    V m_value;
  };
}
