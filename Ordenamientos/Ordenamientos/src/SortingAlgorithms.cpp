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

std::vector<int> 
SortingAlgorithms::insertionSort( std::vector<int> numbers )
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

std::vector<int>
SortingAlgorithms::quickSort( std::vector<int>& numbers, 
                                               int left,
                                               int right )
{
  if ( left < right )
  {

    int pi = partition( numbers, left, right );

    quickSort( numbers, left, pi - 1 );
    quickSort( numbers, pi + 1, right );
  }

  return numbers;
}

std::vector<int>
SortingAlgorithms::mergeSort( std::vector<int>& numbers, int left, int right )
{
  if ( left < right )
  {
    int mid = left + ( right - left ) / 2;

    mergeSort( numbers, left, mid );
    mergeSort( numbers, mid+ 1, right );

    merge( numbers, left, mid, right );
  }
  return numbers;
}

int 
SortingAlgorithms::binarySearch( std::vector<int> numbers, 
                                 int left, 
                                 int right, 
                                 int x )
{
  if ( right >= left )
  {
    int mid = left + ( right - left ) / 2;

    if ( numbers[mid] == x )
    {
      return mid;
    }

    if ( numbers[mid] > x )
    {
      return binarySearch( numbers, left, mid - 1, x );
    }

    return binarySearch( numbers, mid + 1, right, x );
  }

  return -1;
}

int SortingAlgorithms::linearSearch( std::vector<int> numbers, int x )
{
  
  for ( int i = 0; i < numbers.size(); i++ )
    if ( numbers[i] == x )
      return i;
  return -1;

}

int 
SortingAlgorithms::partition( std::vector<int>& numbers, int start, int end )
{
  unsigned int pivot = numbers[start];
  unsigned int left = start + 1;
  unsigned int right = end;
  unsigned int tmp;

  while ( left != right )
  {
    if ( numbers[left] <= pivot ) left++;
    else
    {
      while ( ( left != right ) && ( pivot < numbers[right] ) ) right--;
      tmp = numbers[right];
      numbers[right] = numbers[left];
      numbers[left] = tmp;
    }
  }

  if ( numbers[left] > pivot ) left--;
  numbers[start] = numbers[left];
  numbers[left] = pivot;

  return ( left );
}

void 
SortingAlgorithms::merge( std::vector<int>& numbers, int left, int mid, int right )
{
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<int> Left, Right;

  for ( i = 0; i < n1; i++ )
    Left.push_back( numbers[left + i] );
  for ( j = 0; j < n2; j++ )
    Right.push_back( numbers[mid + 1 + j] );

  i = 0;
  j = 0;
  k = left;

  while ( i < n1 && j < n2 )
  {
    if ( Left[i] <= Right[j] )
    {
      numbers[k] = Left[i];
      i++;
    }
    else
    {
      numbers[k] = Right[j];
      j++;
    }
    k++;
  }

  while ( i < n1 )
  {
    numbers[k] = Left[i];
    i++;
    k++;
  }

  while ( j < n2 )
  {
    numbers[k] = Right[j];
    j++;
    k++;
  }

}
