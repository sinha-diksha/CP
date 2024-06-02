#include <bits/stdc++.h>
using namespace std;

void buildTree(vector<int> &arr, vector<int> &temp, int treeNode, int s, int e)
{

  if (s == e)
  {
    temp[treeNode] = arr[s];
    return;
  }

  int mid = (s + e) / 2;
  buildTree(arr, temp, treeNode * 2, s, mid);
  buildTree(arr, temp, treeNode * 2 + 1, mid + 1, e);
  temp[treeNode] = min(temp[treeNode * 2], temp[treeNode * 2 + 1]);
}

void update(vector<int> &arr, vector<int> &temp, int treeNode, int idx, int val, int s, int e)
{
  if (s == e)
  {
    arr[idx] = val;
    temp[treeNode] = val;
    return;
  }
  int mid = (s + e) / 2;
  if (idx > mid)
  {
    update(arr, temp, treeNode * 2 + 1, idx, val, mid + 1, e);
  }
  else
  {
    update(arr, temp, treeNode * 2, idx, val, s, mid);
  }
  temp[treeNode] = min(temp[treeNode * 2], temp[treeNode * 2 + 1]);
}

int query(vector<int> &temp, int s, int e, int treeNode, int l, int r)
{
  if (s > r || e < l)
  {
    return 0;
  }

  if (s >= l && e <= r)
  {
    return temp[treeNode];
  }
  int mid = (s + e) / 2;
  int a1 = query(temp, s, mid, treeNode * 2, l, r);
  int a2 = query(temp, mid + 1, e, treeNode * 2 + 1, l, r);
  return min(a1, a2);
}
int main()
{

  // write your code here
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  vector<int> tree(4 * n);
  buildTree(arr, tree, 1, 0, n - 1);

  for (int i = 0; i < m; i++)
  {
    char c;
    int a, b;
    cin >> c >> a >> b;
    if (c == 'q')
    {
      cout << query(tree, 0, n - 1, 1, a, b) << endl;
      ;
    }
    else
    {
      update(arr, tree, 1, a, b, 0, n - 1);
    }
  }
  return 0;
}