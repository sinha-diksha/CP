#include <bits/stdc++.h>
using namespace std;

void buildTree(int *arr, int *tree, int s, int e, int idx)
{
  if (s == e)
  {
    tree[idx] = arr[s];
    return;
  }
  int mid = (s + e) / 2;
  buildTree(arr, tree, s, mid, 2 * idx);
  buildTree(arr, tree, mid + 1, e, 2 * idx + 1);
  tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}
void update(int *arr, int *tree, int s, int e, int treeNode, int idx, int val)
{
  if (s == e)
  {
    arr[idx] = val;
    tree[treeNode] = val;
    return;
  }
  int mid = (s + e) / 2;
  if (idx > mid)
  {
    update(arr, tree, mid + 1, e, treeNode * 2 + 1, idx, val);
  }
  else
  {
    update(arr, tree, s, mid, treeNode * 2, idx, val);
  }

  tree[treeNode] = tree[treeNode * 2] + tree[treeNode * 2 + 1];
}

int query(int *tree, int s, int e, int treeNode, int l, int r)
{
  if (e < l || s > r)
  {
    return 0;
  }

  if (s >= l && e <= r)
  {
    return tree[treeNode];
  }

  int mid = (s + e) / 2;
  int a1 = query(tree, s, mid, treeNode * 2, l, r);
  int a2 = query(tree, mid + 1, e, treeNode * 2 + 1, l, r);
  return a1 + a2;
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int *tree = new int[10];
  buildTree(arr, tree, 0, 4, 1);

    for (int i = 1; i < 10; i++)
  {
    cout << tree[i] << endl;
  }
}