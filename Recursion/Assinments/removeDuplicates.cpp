#include <bits/stdc++.h>
using namespace std;

void removeConsecutiveDuplicates(char *input)
{
  if (input[0] == '\0')
  {
    return;
  }
  removeConsecutiveDuplicates(input + 1);
  if (input[0] == input[1])
  {
    for (int i = 0; input[i] != '\0'; i++)
    {
      input[i] = input[i + 1];
    }
  }
  return;
}