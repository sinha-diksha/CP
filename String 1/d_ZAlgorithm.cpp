#include <bits/stdc++.h>
using namespace std;

void zFunction(vector<int> &z, int n, string s)
{
  int l = 0;
  int r = 0;

  for (int i = 1; i < n; i++)
  {
    if (i > r)
    {
      l = i;
      r = i;
      while (r < n && s[r - l] == s[r])
      {
        r++;
      }
      z[i] = r - l;
      r--;
    }
    else
    {
      int k = i - l;
      if (z[k] + i <= r)
      {
        z[i] = z[k];
      }
      else
      {
        l = i;

        while (r < n && s[r - l] == s[r])
        {
          r++;
        }
        z[i] = r - l;
        r--;
      }
    }
  }
}

int main()
{
  string text;
  string pattern;
  cin >> text >> pattern;
  string ans = pattern + "$" + text;
  int n = ans.size();
  vector<int> z(n);
  zFunction(z, n, ans);
  int m = pattern.size();
  int count = 0;
  for (int i = m; i < n; i++)
  {
    if (z[i] == m)
    {
      count++;
    }
  }
  cout << count << endl;
}