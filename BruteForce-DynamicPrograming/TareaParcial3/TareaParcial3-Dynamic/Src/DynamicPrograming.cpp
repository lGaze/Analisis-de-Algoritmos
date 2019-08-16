#include <vector>
#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace chrono;

void 
lcs(string X, string Y, unsigned int m, unsigned int n)
{
  vector<vector<unsigned int>> L(0);
  L.resize(m + 1);
  for (auto& it : L) {
    it.resize(n + 1);
  }

  for (unsigned int i = 0; i < m + 1; ++i) {
    for (unsigned int j = 0; j < n + 1; ++j) {
      if (i == 0 || j == 0) {
        L[i][j] = 0;
      }
      else {
        if (X[i - 1] == Y[j - 1]) {
          L[i][j] = L[i - 1][j - 1] + 1;
        }
        else {
          L[i][j] = (unsigned int)(fmax(L[i - 1][j], L[i][j - 1]));
        }
      }
    }
  }

  unsigned int index = L[m][n];
  string lcs("");
  lcs.resize(index + 1);

  unsigned int i = m;
  unsigned int j = n;
  while ((i > 0) && (j > 0)) {
    if (X[i - 1] == Y[j - 1]) {
      lcs[index - 1] = X[i - 1];
      --i;
      --j;
      --index;
    }
    else {
      if (L[i - 1][j] > L[i][j - 1]) {
        --i;
      }
      else {
        --j;
      }
    }
  }

  cout << "La subsecuencia mas larga comun de " <<
    X.c_str() << " y de " << Y.c_str() << " es " << lcs.c_str() << endl;
}

int main() {

  string X("TTCGCATCGGGTTG");
  string Y("TGACCGTGTGTCACG");

  time_point<steady_clock> start = high_resolution_clock::now();

  cout << "---Dynamic Programming---" << endl;

  lcs(X, Y, X.size(), Y.size());

  time_point<steady_clock> end = high_resolution_clock::now();

  cout << "Terminado en: " <<
    duration_cast<seconds>(end - start).count() / 1e+9 <<
    " segundos." << endl;

  system("pause");
  return 0;
}
