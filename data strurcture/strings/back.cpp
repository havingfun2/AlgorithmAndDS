#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
  std::string str ("hello world.");
  str.back() = '!';
  std::cout << str << '\n';
  return 0;
}

