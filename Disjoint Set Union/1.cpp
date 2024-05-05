// Here We will implement DSU
#include <bits/stdc++.h>
using namespace std;

class DSU
{
  vector<int> parent;

public:
  DSU(int n)
  {
    parent = vector<int>(n + 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
    }
  }

  int findRoot(int x)
  {
    while (x != parent[x])
    {
      x = parent[x];
    }

    return x;
  }

  int combine(int x, int y)
  {
    int rx = findRoot(x);
    int ry = findRoot(y);
    if (rx == ry)
    {
      return 0;
    }
    else
    {
      parent[rx] = ry;
      return 1;
    }
  }
};

int main()
{
  int t;
  cin >> t;
  int n;
  cin >> n;
  DSU dsu(n);
  while (t--)
  {
    int q;
    cin >> q;
    while (q--)
    {
      int type, x, y;
      cin >> type;
      cin >> x;
      cin >> y;
      if (type == 1)
      {
        int r = dsu.combine(x, y);
      }
      else
      {
        int rx = dsu.findRoot(x);
        int ry = dsu.findRoot(y);
        if (rx == ry)
        {
          cout << "YES" << endl;
        }
        else
        {
          cout << "NO" << endl;
        }
      }
    }
  }
}