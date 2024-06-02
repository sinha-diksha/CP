#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int maximum;
  int smaximum;
};

void buildTree(vector<int> &arr, vector<Node> &tree, int treeNode, int s, int e)

{
  if (s == e)
  {
    tree[treeNode].maximum = arr[s];
    tree[treeNode].smaximum = INT_MIN;
    return;
  }
  int mid = (s + e) / 2;
  buildTree(arr, tree, treeNode * 2, s, mid);
  buildTree(arr, tree, treeNode * 2 + 1, mid + 1, e);
  Node left = tree[treeNode * 2];
  Node right = tree[treeNode * 2 + 1];
  tree[treeNode].maximum = max(left.maximum, right.maximum);
  tree[treeNode].smaximum = min(max(left.maximum, right.smaximum), max(right.maximum, left.smaximum));
  return;
}

void update(vector<int> &arr, vector<Node> &tree, int treeNode, int s, int e, int idx, int val)

{
  if (s == e)
  {
    arr[idx] = val;
    tree[treeNode].maximum = val;
    tree[treeNode].smaximum = INT_MIN;
    return;
  }
  int mid = (s + e) / 2;
  if (idx > mid)
  {
    update(arr, tree, treeNode * 2 + 1, mid + 1, e, idx, val);
  }
  else
  {
    update(arr, tree, treeNode * 2, s, mid, idx, val);
  }

  Node left = tree[treeNode * 2];
  Node right = tree[treeNode * 2 + 1];
  tree[treeNode].maximum = max(left.maximum, right.maximum);
  tree[treeNode].smaximum = min(max(left.maximum, right.smaximum), max(right.maximum, left.smaximum));
  return;
}

Node query(vector<Node> &tree, int treeNode, int s, int e, int l, int r)
{
  if (e < l || s > r)
  {
    Node n;
    n.maximum = INT_MIN;
    n.smaximum = INT_MIN;
    return n;
  }

  if (s >= l && e <= r)
  {
    Node n;
    n.maximum = tree[treeNode].maximum;
    n.smaximum = tree[treeNode].smaximum;
    return n;
  }
  int mid = (s + e) / 2;
  Node left = query(tree, treeNode * 2, s, mid, l, r);
  Node right = query(tree, treeNode * 2 + 1, mid + 1, e, l, r);
  Node n;
  n.maximum = max(left.maximum, right.maximum);
  n.smaximum = min(max(left.maximum, right.smaximum), max(right.maximum, left.smaximum));
  return n;
}

main()
{
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  vector<Node> tree(4 * n);

  buildTree(arr, tree, 1, 0, n - 1);

  //   for(int i=1; i<4*n; i++){
  //       cout<<tree[i].maximum<<" "<<tree[i].smaximum<<endl;
  //   }
  int m;
  cin >> m;

  for (int i = 0; i < m; i++)
  {
    char c;
    int a, b;
    cin >> c >> a >> b;
    if (c == 'Q')
    {
      Node n1 = query(tree, 1, 0, n - 1, a - 1, b - 1);
      cout << n1.maximum + n1.smaximum << endl;
    }
    else
    {
      update(arr, tree, 1, 0, n - 1, a - 1, b);
    }
  }
}