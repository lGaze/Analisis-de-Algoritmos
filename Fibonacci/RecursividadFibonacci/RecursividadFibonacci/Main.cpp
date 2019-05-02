#include <iostream>
#include <chrono>

int FibonacciRecursiva( int n )
{
  if (n <= 1)
    return n;

  else
    return FibonacciRecursiva( n - 1 ) + FibonacciRecursiva( n - 2 );
}

int FibonacciNoRecursiva( int n )
{
  int 
    x = 0;
  int
    n1 = 0;
  int
    n2 = 1;

  if (n <= 1)
  {
    return n;
  }

  else
  {
    int
      f = 0;

    for (int i = 1; i < n; i++)
    {
      f = n1 + n2;
      n1 = n2;
      n2 = f;
    }

    return f; 
  }
}

int main()
{
  while ( true )
  {
    int n;

    std::chrono::time_point<std::chrono::system_clock> start, end;

    std::cout << 
      " Introduce el numero en la secuencia de Fibonacci que quieres calcular: " << 
      std::endl;

    std::cin >> n;
    
    start = std::chrono::system_clock::now();

    std::cout << "El numero en la secuencia de Fibonacci es: " << n << std::endl;
    

    std::cout <<
      "El valor correspondiente con algoritmo fibonacci No Recursivo es: " <<
      FibonacciNoRecursiva( n ) <<
      " Terminado en " << 
      std::endl;

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> seg = end - start;
    std::cout << "Tiempo transcurrido: " << seg.count() << std::endl;

    start = std::chrono::system_clock::now();
    

    std::cout <<
      "El valor correspondiente con algoritmo de Fibonacci Recursivo es: " <<
      FibonacciRecursiva( n ) <<
      " Terminado en " <<
      std::endl;

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> seg2 = end - start;
    std::cout << "Tiempo transcurrido: " << seg2.count() << std::endl;

  }
}