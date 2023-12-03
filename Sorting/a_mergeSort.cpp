#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int si, int mid, int ei)
{
  int n = mid - si + 1;
  int m = ei - mid;

  vector<int> arr1(n);
  vector<int> arr2(m);
  int k = si;
  for (int i = 0; i < n; i++)
  {
    arr1[i] = v[k++];
  }
  for (int i = 0; i < m; i++)
  {
    arr2[i] = v[k++];
  }

  int i = 0;
  int j = 0;
  vector<int> newAns(n + m);
  k = 0;
  while (i < n && j < m)
  {
    if (arr1[i] <= arr2[j])
    {
      newAns[k++] = arr1[i];
      i++;
    }
    else
    {
      newAns[k++] = arr2[j];
      j++;
    }
  }

  while (i < n)
  {
    newAns[k++] = arr1[i];
    i++;
  }
  while (j < m)
  {
    newAns[k++] = arr2[j];
    j++;
  }
  k = 0;
  for (int i = si; i <= ei; i++)
  {
    v[i] = newAns[k++];
  }
}

void mergeSort(vector<int> &v, int si, int ei)
{
  if (si >= ei)
  {
    return;
  }

  int mid = (si + ei) / 2;
  mergeSort(v, si, mid);
  mergeSort(v, mid + 1, ei);
  merge(v, si, mid, ei);
}
int main()
{

  // write your code here
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
    mergeSort(v, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
      cout << v[i] << " ";
    }
    cout << endl;
  }
  return 0;
}