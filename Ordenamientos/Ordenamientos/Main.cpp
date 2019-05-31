#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>    
#include "include/SortingAlgorithms.h"

/**
 * @brief Function that creates a Vector of int numbers from 1 to the given number.
 * @param Int number that indicates the last number of the vector.
 * @return The Vector with the numbers in ascending order.
 */
std::vector<int> 
ascendingOrder( int num )
{
  std::vector<int> numeros;

  for (int i = 1; i <= num; i++)
  {
    numeros.push_back(i);
  }
  return numeros;
}

/**
 * @brief Function that creates a Vector of int numbers from the given number to 1.
 * @param Int number that indicates the first number of the vector.
 * @return The Vector with the numbers in descending order.
 */
std::vector<int> 
descendingOrder( int num )
{
  std::vector<int>
  numeros;

  for (int i = num; i >= 1; i--)
  {
    numeros.push_back( i );
  }
  return numeros;
}

/**
 * @brief Function that creates a Vector of int numbers from 1 to the given number in random order.
 * @param Int number that indicates the first number of the vector.
 * @return The Vector with the random numbers.
 */
std::vector<int> 
randomNumbers( int num )
{
  int randNum = 0;

  std::vector<int> numeros;

  srand( time( NULL ) );
  
  for ( int i = 1; i <= num; i++ )
  {
    numeros.push_back( rand() % num + 1 );
  }
  return numeros;
}

/**
 * @brief Funtion that prints a given Vector 
 * @param Vector of the numbers to print
 */
void
printVector( std::vector<int> numbers )
{
  for ( int i = 0; i < numbers.size(); i++ )
  {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;
}

int main()
{
  std::vector<int> RandomNums = randomNumbers( 2500 );
  std::vector<int> AscendentNums = ascendingOrder( 2500 );
  std::vector<int> DescendentNums = descendingOrder( 2500 );
  int numberToSearch = 50;

  SortingAlgorithms algorithm;

  //std::cout << "Entry Vector:\n " << std::endl;s
  //
  //printVector( RandomNums );
  //
  //std::cout << "\nBubble Sorting:\n " << std::endl;
  //
  //printVector( algorithm.bubbleSort( RandomNums ) );
  //
  //std::cout << "\nElapsed Time: " << algorithm.seg.count() << " segs" << std::endl;
  //
  //std::cout << "\nInsertion Sorting:\n " << std::endl;
  //
  //printVector( algorithm.insertionSort( RandomNums ) );
  //
  //std::cout << "\nElapsed Time: " << algorithm.seg.count() << " segs" << std::endl;
  
 // std::cout << "Linear Search of the number: " << numberToSearch << std::endl;
 //
 // std::cout << "Te number is in the position : " << 
 //   algorithm.linearSearch( AscendentNums, 50 ) <<
 //   std::endl;
 //
 // std::cout << "Bynary Search of the number: " << numberToSearch << std::endl;
 //
 // std::cout << "Te number is in the position : " <<
 //   algorithm.binarySearch( AscendentNums,
 //                           AscendentNums.front(),
 //                           AscendentNums.back(),
 //                           numberToSearch ) <<
 //  std::endl;


  std::cout << "Counting Sorting: " << std::endl;
  printVector( algorithm.countingSort( DescendentNums ));

  std::cout << "\nElapsed Time: " << algorithm.seg.count() << " segs" << std::endl;

  std::cout << "Radix Sorting: " << std::endl;
 
  printVector( algorithm.radixSort( DescendentNums ) );

  std::cout << "\nElapsed Time: " << algorithm.seg.count() << " segs" << std::endl;

 
  system( "pause" );
  return 0;
}