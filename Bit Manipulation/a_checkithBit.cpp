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
    int k;
    cin >> k;
    if ((n & (1 << k)) == 0)
    {
      cout << "unset" << endl;
    }
    else
    {
      cout << "set" << endl;
    }
  }
}