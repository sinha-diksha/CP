#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int main()
{
  // write your code here
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    long long sum = 0;
    for (long long i = 1; i <= n; i++)
    {
      long long g = __gcd(i, n);
      cout << g << endl;
      long long lc = ((1 * n) / g);
      sum += lc;
    }

    cout << sum << endl;
  }
  return 0;
}
