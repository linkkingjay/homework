#include <string>
#include <fstream>
using namespace std;

int main() {
  ifstream in("scopy.cpp"); // Open for reading
  ofstream out("scopy2.cpp"); // Open for wrinting
  string s;
  while (getline(in, s)) // Discards newline char
    out << s << "\n"; // ... must add it back
}
