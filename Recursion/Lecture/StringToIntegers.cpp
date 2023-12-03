#include <bits/stdc++.h>
using namespace std;
int stringToNumber(char input[], int s, int e, int size)
{

  if (s == e)
  {
    return input[s] - '0';
  }

  int smallAns = stringToNumber(input, s, e - 1, size - 1);
  int n = smallAns;
  int r = 0;
  while (n > 0)
  {
    r++;
    n = n / 10;
  }

  int l = ((smallAns) * 10) + (input[e] - '0');

  return l;
}

int stringToNumber(char input[])
{
  // Write your code here
  int e = 0;
  for (int i = 0; input[i] != '\0'; i++)
  {
    e++;
  }

  return stringToNumber(input, 0, e - 1, e);
}