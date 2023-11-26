#include <bits/stdc++.h>
using namespace std;
#define long long
#define double long double

static bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
  return a.first.first < b.first.first;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> v;
    int i = 0;
    while (n--)
    {
      int a, b;
      cin >> a >> b;
      pair<pair<int, int>, int> p1;
      p1.first.first = a;
      p1.second = i;
      p1.first.second = b;
      v.push_back(p1);
      i++;
    }

    sort(v.begin(), v.end(), cmp);

    int ans = 0;
    vector<int> ans1(n, -1);
    for (int i = 0; i < n; i++)
    {
      if (ans1[i] == -1)
      {
        ans += v[i].first.first;
        ans1[i] = 0;
      }
      else
      {
        continue;
      }
      int s = v[i].second + 1;
      int lastVal = v[i].first.second;
      while (s < n)
      {
        if (v[s].first.first - lastVal > 0)
        {
          v[s].first.first -= lastVal;
          break;
        }
        else
        {
          v[s].first.first = 0;
          lastVal = v[s].second;
          s++;
        }
      }
    }

    cout << ans << endl;
  }
  return 1;
}