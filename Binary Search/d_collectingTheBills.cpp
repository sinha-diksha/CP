#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long mid, long long n)
{
  long long m = n;
  long long Sharma = 0;
  long long i = 0;

  while (n > 0)
  {
    if (i % 2 == 0)
    {
      long long chocolates_taken = min(mid, n);
      Sharma += chocolates_taken;
      n -= chocolates_taken;
    }
    else
    {
      n -= n / 10;
    }
    i++;
  }

  return (2 * Sharma) >= m;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {

    long long int n;
    cin >> n;
    long long l = 1;
    long long h = n;
    long long ans = h;
    while (l <= h)
    {
      long long mid = l + (h - l) / 2;

      if (isPossible(mid, n))
      {
        ans = mid;

        h = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }
    cout << ans << endl;
  }
  // write your code here
  return 0;
}