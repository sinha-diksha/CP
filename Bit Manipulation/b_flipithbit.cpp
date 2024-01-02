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
    n = (n ^ (1 << k));
    cout << n << endl;
  }
}