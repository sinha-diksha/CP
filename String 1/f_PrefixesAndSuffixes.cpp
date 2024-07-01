/*D. Prefixes and Suffixes
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have a string s = s1s2...s|s|, where |s| is the length of string s, and si its i-th character.

Let's introduce several definitions:

A substring s[i..j] (1 ≤ i ≤ j ≤ |s|) of string s is string sisi + 1...sj.
The prefix of string s of length l (1 ≤ l ≤ |s|) is string s[1..l].
The suffix of string s of length l (1 ≤ l ≤ |s|) is string s[|s| - l + 1..|s|].
Your task is, for any prefix of string s which matches a suffix of string s, print the number of times it occurs in string s as a substring.

Input
The single line contains a sequence of characters s1s2...s|s| (1 ≤ |s| ≤ 105) — string s. The string only consists of uppercase English letters.

Output
In the first line, print integer k (0 ≤ k ≤ |s|) — the number of prefixes that match a suffix of string s. Next print k lines, in each line print two integers li ci. Numbers li ci mean that the prefix of the length li matches the suffix of length li and occurs in string s as a substring ci times. Print pairs li ci in the order of increasing li.*/

#include <bits/stdc++.h>
using namespace std;

void zAlgorithm(string s, int n, vector<int> &z)
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

void solve()
{
  string s;
  cin >> s;
  int n = s.length();
  vector<int> z(n);
  zAlgorithm(s, n, z);
  z[0] = n;

  vector<int> freq(n + 1);
  for (int i = 0; i < n; i++)
  {
    freq[z[i]]++;
  }

  for (int i = n - 1; i >= 0; i--)
  {
    freq[i] = freq[i + 1] + freq[i];
  }
  vector<pair<int, int>> ans;
  for (int i = n - 1; i >= 0; i--)
  {

    if (i + z[i] == n)
    {
      ans.push_back({z[i], freq[z[i]]});
    }
  }

  cout << ans.size() << "\n";
  for (auto i : ans)
  {
    cout << i.first << " " << i.second << "\n";
  }
}

int main()
{
  solve();
  return 0;
}