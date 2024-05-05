// Modular Exponentiation
#include <bits/stdc++.h>
using namespace std;

int modExp(int a, int b, int c)
{
  if (a == 0)
  {
    return 0;
  }
  if (b == 1)
  {
    return a;
  }
  long ans;
  if (b % 2 == 0)
  {
    long smallAns = modExp(a, b / 2, c);
    ans = (smallAns % c * smallAns % c) % c;
  }
  else
  {
    long smallAns = modExp(a, b - 1, c);
    ans = (a % c);
    ans = (ans % c * smallAns % c) % c;
  }

  return int((ans + c) % c);
}

int main()
{
  int a = 2;
  int b = 5;
  int c = 5;
  cout << modExp(a, b, c) << endl;
  return 0;
}
