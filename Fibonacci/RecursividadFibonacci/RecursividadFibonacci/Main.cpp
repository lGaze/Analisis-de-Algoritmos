#include <iostream>


int FibonacciRecursiva( int n )
{
  if (n <= 1)
  {
    return n;
  }
  else
  {
    return FibonacciRecursiva( n - 1 ) + FibonacciRecursiva( n - 2 );
  }
}

int FibonacciNoRecursiva( int n )
{
  int x = 0;
  int n1 = 0;
  int n2 = 1;

  if (n <= 1)
  {
    return n;
  }

  else
  {
    for (int i = 0; i < n; i++)
    {
      int f = n1 + n2;
      n1 = n2;
      n2 = f;
      x = x + 1;
      return f; 
    }
  }
}

int main()
{
  while ( true )
  {
    int n;

    std::cout << 
      " Introduce el numero en la secuencia de Fibonacci que quieres calcular: " << 
      std::endl;

    std::cin >> n;
    
    std::cout << "El numero en la secuencia de Fibonacci es: " << n << std::endl;
    
    std::cout <<
      "El valor correspondiente con algoritmo fibonacci No Recursivo es: " <<
      FibonacciNoRecursiva( n ) <<
      " Terminado en " << 
      std::endl;

    std::cout <<
      "El valor correspondiente con algoritmo de Fibonacci Recursivo es: " <<
      FibonacciRecursiva( n ) <<
      " Terminado en " <<
      std::endl;
  }
}