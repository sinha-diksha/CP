#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    if ((n & (n - 1)) == 0)
    {
      cout << "power of two" << endl;
    }
    else
    {
      cout << "not a power of two" << endl;
    }
  }
}