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
    if ((n & (1 << 0)) == 0)
    {
      cout << "even" << endl;
    }
    else
    {
      cout << "odd" << endl;
    }
  }
}