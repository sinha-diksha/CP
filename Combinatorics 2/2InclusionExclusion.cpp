#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b)
{
  if (b == 0)
  {
    return a;
  }
  return gcd(b, a % b);
}

ll inEx(ll n, ll k, vector<ll> divisor)
{
  ll res = 0;
  for (ll i = 1; i < (pow(2, k)); i++)
  {
    ll lcm = 1;
    ll count = 0;
    for (ll j = 0; j <= k - 1; j++)
    {
      if ((i & (1 << j)))
      {
        ll gcd1 = gcd(lcm, divisor[j]);
        lcm = (lcm * divisor[j]) / gcd1;
        count++;
      }
    }
    if (count % 2 != 0)
    {
      res += (n / lcm);
    }
    else
    {
      res -= (n / lcm);
    }
    }
  return n - res;
}

int main()
{
  long long n;
  cin >> n;
  long long k;
  cin >> k;
  vector<long long> divisor(k);
  for (int i = 0; i < k; i++)
  {
    cin >> divisor[i];
  }
  cout << inEx(n, k, divisor) << endl;
  return 0;
}