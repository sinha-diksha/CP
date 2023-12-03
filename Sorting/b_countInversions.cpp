#include <bits/stdc++.h>
using namespace std;

int merge(long long *arr, int si, int mid, int ei)
{
  int n = mid - si + 1;
  int m = ei - mid;
  long long arr1[n];
  long long arr2[m];
  int k = si;
  for (int i = 0; i < n; i++)
  {

    arr1[i] = arr[k++];
  }

  for (int i = 0; i < m; i++)
  {
    arr2[i] = arr[k++];
  }
  int numInverstion = 0;
  int i = 0;
  int j = 0;
  long long finalArray[n + m];
  k = 0;
  while (i < n && j < m)
  {
    if (arr1[i] <= arr2[j])
    {
      finalArray[k++] = arr1[i];
      i++;
    }
    else
    {
      numInverstion += (n - i);
      finalArray[k++] = arr2[j];
      j++;
    }
  }

  while (i < n)
  {
    finalArray[k++] = arr1[i];
    i++;
  }
  while (j < m)
  {

    finalArray[k++] = arr2[j];
    j++;
  }

  k = 0;
  for (int i = si; i <= ei; i++)
  {
    arr[i] = finalArray[k++];
  }
  return numInverstion;
}

int mergeSort(long long *arr, int si, int ei)
{
  if (si >= ei)
  {
    return 0;
  }

  int mid = (si + ei) / 2;
  int leftInversion = mergeSort(arr, si, mid);
  int rightInversion = mergeSort(arr, mid + 1, ei);
  int totalInversion = merge(arr, si, mid, ei);
  return leftInversion + rightInversion + totalInversion;
}

long long getInversions(long long *arr, int n)
{
  // Write your code here.
  return mergeSort(arr, 0, n - 1);
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    long long arr[n];

    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }

    cout << getInversions(arr, n) << endl;
  }
}