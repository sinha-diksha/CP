#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

vector<int> findRepeatingAndMissingNumbers(vector<int> nums)
{
  // Write your code here.
  int resultXor = 0;
  for (auto i : nums)
  {
    resultXor ^= i;
  }

  for (int i = 1; i <= nums.size(); i++)
  {
    resultXor ^= i;
  }

  int setBits = resultXor & (~(resultXor - 1));

  int x = 0;
  int y = 0;
  for (auto i : nums)
  {

    if ((i & setBits) != 0)
    {
      x ^= i;
    }
    else
    {
      y ^= i;
    }
  }
  for (int i = 1; i <= nums.size(); i++)
  {
    if ((i & setBits) != 0)
    {
      x ^= i;
    }
    else
    {
      y ^= i;
    }
  }

  vector<int> ans;
  for (auto i : nums)
  {
    if (x == i)
    {
      ans.push_back(x);
      ans.push_back(y);
      return ans;
      break;
    }
  }
  ans.push_back(y);
  ans.push_back(x);
  return ans;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
      cin >> v[i];
    }
    vector<int> ans = findRepeatingAndMissingNumbers(v);
    cout << ans[0] << " " << ans[1] << endl;
  }
}