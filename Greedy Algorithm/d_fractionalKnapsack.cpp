#include <bits/stdc++.h>
using namespace std;
int main()
{

    // write your code here
    cout << fixed << endl;
    cout << setprecision(6);
    double n, w;
    cin >> n >> w;
    vector<pair<double, pair<double, double>>> v(n);
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        double r = x / y;
        pair<double, double> p;
        p.first = x;
        p.second = y;
        v[i].first = r;
        v[i].second = p;
    }
    sort(v.begin(), v.end(), greater<pair<double, pair<double, double>>>());

    int i = 0;
    double ans = 0;
    while (w != 0 && i < n)
    {
        if (w >= v[i].second.second)
        {
            ans += v[i].second.first;
            w -= v[i].second.second;
        }
        else
        {
            ans += (v[i].second.first * w) / v[i].second.second;
            w = 0;
        }

        i++;
    }
    cout << ans << endl;
    return 0;
}