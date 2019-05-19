#include "../include/SortingAlgorithms.h"

SortingAlgorithms::SortingAlgorithms()
{
}

SortingAlgorithms::~SortingAlgorithms()
{
}

std::vector<int> 
SortingAlgorithms::bubbleSort( std::vector<int> numbers )
{
  bool inOrder;

  start = std::chrono::system_clock::now();

  for ( int i = 0; i < numbers.size() - 1; i++ ) {

    inOrder = true;
    for ( int j = 0; j < numbers.size() - i - 1; j++ ) {

      if ( numbers[j] > numbers[j + 1] )
      {
        std::swap( numbers[j], numbers[j + 1] );
        inOrder = false; 
      }
    }

    if (inOrder)
    {
      break;
    }
  }

  end = std::chrono::system_clock::now();

  seg = end - start;

  return numbers;      
}

std::vector<int> SortingAlgorithms::insertionSort( std::vector<int> numbers )
{
  
  start = std::chrono::system_clock::now();

  for ( int i = 1; i < numbers.size(); i++ )
  {

    int pivot = i;
    int j = i - 1;

    while ( j >= 0 && numbers[pivot] < numbers[j]  )
    {
      std::swap( numbers[pivot], numbers[j] );
      pivot = j;
      j = j - 1;
    }
  }

  end = std::chrono::system_clock::now();

  seg = end - start;

  return numbers;

}
