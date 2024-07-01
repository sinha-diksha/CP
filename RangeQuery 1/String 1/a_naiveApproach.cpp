#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s, p;
  cin >> s >> p;
  int n = s.length();
  int m = p.length();
  bool isFound = false;
  for (int i = 0; i <= n - m; i++)
  {
    string k = s.substr(i, m);
    if (k == p)
    {
      isFound = true;
      cout << "Found" << endl;
      break;
    }
  }

  if (!isFound)
  {
    cout << "NOT Found" << endl;
  }
}