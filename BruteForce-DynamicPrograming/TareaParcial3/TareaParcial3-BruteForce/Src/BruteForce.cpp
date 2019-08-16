#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using namespace chrono;


vector<string> 
obtenerSubsecuencias(string secuencia)
{
  unsigned int n = secuencia.size();

  unsigned int numeroDeSubsecuencias = (unsigned int)pow(2, n);

  vector<string> subsecuencias;
  subsecuencias.resize(numeroDeSubsecuencias);
  for (unsigned int i = 1; i < numeroDeSubsecuencias; ++i) {
    string subsecuencia;
    for (unsigned int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        subsecuencia += secuencia[j];
      }
    }
    subsecuencias[i - 1] = subsecuencia;
  }
  return subsecuencias;
}

string 
compararSubsecuencias(vector<string> subsecuencias1,
                      vector<string> subsecuencias2) 
{
  string lcs;
  for (unsigned i = 0; i < subsecuencias1.size(); i++) {
    for (unsigned j = 0; j < subsecuencias2.size(); j++) {
      if (i == j) {
        if (lcs.size() < subsecuencias1[i].size()) {
          lcs = subsecuencias1[i];
        }
      }
    }
  }
  return lcs;
}

int main() 
{

  string secuencia1 = "TTCGCATCGGGTTG";
  string secuencia2 = "TGACCGTGTGTCACG";

  vector<string> subsecuencias1 = obtenerSubsecuencias(secuencia1);
  vector<string> subsecuencias2 = obtenerSubsecuencias(secuencia2);

  time_point<steady_clock> start = high_resolution_clock::now();

  string lcs = compararSubsecuencias(subsecuencias1, subsecuencias2);

  cout << "---Brute Force---" << endl;
  cout << "La subsecuencia mas larga comun de " << secuencia1.c_str() <<
    " y de " << secuencia2.c_str() << " es " << lcs.c_str() << endl;

  time_point<steady_clock> end = high_resolution_clock::now();

  cout << "Terminado en: " <<
    duration_cast<nanoseconds>(end - start).count() / 1e+9 <<
    " segundos." << endl;

  system("pause");
  return 0;
}
