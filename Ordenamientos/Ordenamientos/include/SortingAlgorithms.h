/**************************************************************************/
/* @filename SortingAlgorithms.h
/* @author Victor Flores 
/* @date 2019/05/16
/* @brief Class with helper functions for sorting
/**************************************************************************/
#pragma once
#include <iostream>
#include <vector>
#include <chrono>

class SortingAlgorithms
{
public:

  /**
   * @brief Default Constructor
   */
  SortingAlgorithms();

  /**
   * @brief Default Constructor
   */
  ~SortingAlgorithms();

  /**
   * @brief 
   */
  std::vector<int>
  bubbleSort( std::vector<int> numbers );

  /**
   * @brief 
   */
  std::vector<int>
  insertionSort( std::vector<int> numbers );

  
  std::chrono::time_point<std::chrono::system_clock> start, end;

  std::chrono::duration<double> seg;

};
