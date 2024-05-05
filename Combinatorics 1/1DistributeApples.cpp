#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = (1e9 + 7);

class Triplet
{
public:
  ll gcd;
  ll x;
  ll y;
};

ll fact(int n)
{
  ll res = 1;
  for (int i = 1; i <= n; i++)
  {
    res = (res * i) % mod;
  }
  return res;
}

Triplet extendedEuclid(ll a, ll b)
{
  if (b == 0)
  {
    Triplet ans;
    ans.gcd = a;
    ans.x = 1;
    ans.y = 0;
    return ans;
  }
  Triplet SmallAns = extendedEuclid(b, a % b);
  Triplet ans;
  ans.gcd = SmallAns.gcd;
  ans.x = SmallAns.y;
  ans.y = SmallAns.x - ((a / b) * SmallAns.y);
  return ans;
}

ll modInv(ll n)
{
  Triplet ans = (extendedEuclid(n, mod));

  return (ans.x % mod + mod) % mod;
}

ll C(int n, int r)
{

  ll res = fact(n);

  ll b = modInv(fact(n - r));

  ll c = modInv(fact(r));

  res = (res * b) % mod;
  res = (res * c) % mod;
  return res;
}

int main()
{
  int n, m;
  cin >> n >> m;
  cout << C(n + m - 1, m) << endl;
  return 0;
}