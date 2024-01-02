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
    int z = (1 << (k + 1));
    z = z - 1;
    z = ~z;
    n = n & z;
    cout << n << endl;
  }
}