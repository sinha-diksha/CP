
#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string &str, int s, int e)
{
  if (s >= e)
  {
    return true;
  }
  if (str[s] != str[e])
  {
    return false;
  }
  s += 1;
  e--;
  return isPalindrome(str, s, e);
}
bool isPalindrome(string &str)
{
 
  int n = str.length();
  int s = 0;
  int e = n - 1;
  return isPalindrome(str, s, e);
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    cout << isPalindrome(s) << endl;
  }
}