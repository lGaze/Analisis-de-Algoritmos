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
   * @brief Default destructor
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

  /**
   * @brief 
   */
  std::vector<int>
  quickSort( std::vector<int>& numbers, int left, int right );

  /**
   * @brief 
   */
  std::vector<int>
  mergeSort( std::vector<int>& numbers, int left, int right );

  /**
   * @brief 
   */
  int
  binarySearch( std::vector<int> numbers, int left, int right, int x );

  /**
   * @brief 
   */
  int
  linearSearch( std::vector<int> numbers, int x );

 
  std::chrono::duration<double> seg;
  
private:

  /**
   * @brief 
   */
  int
  partition( std::vector<int>& numbers, int start, int end );

  /**
   * @brief 
   */
  void
  merge( std::vector<int>& numbers, int left, int mid, int right );

  std::chrono::time_point<std::chrono::system_clock> start, end;


};
