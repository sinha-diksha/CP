#include <bits/stdc++.h>
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

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      ans ^= x;
    }
    cout << ans << endl;
  }
  return 0;
}