#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &cost, int n, int p, int mask, vector<int> &dp)
{
  if (p >= n)
  {
    return 0;
  }
  if (dp[mask] != -1)
  {
    return dp[mask];
  }
  int mini = INT_MAX;
  for (int j = 0; j < n; j++)
  {
    if (!(mask & (1 << j)))
    {
      int ans = solve(cost, n, p + 1, mask | (1 << j), dp) + cost[p][j];
      mini = min(ans, mini);
    }
  }
  return dp[mask] = mini;
}
// 10 2 6 5 1 15 12 8 7 8 9 3 15 13 4 10
int main()
{

  int n;
  cin >> n;
  vector<vector<int>> cost(n, vector<int>(n, 0));
  vector<int> dp((1 << n), -1);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> cost[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << cost[i][j] << " ";
    }
  }
  cout << endl;
  cout << solve(cost, n, 0, 0, dp) << endl;
}