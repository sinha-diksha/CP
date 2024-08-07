#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
  double x, y;
};

class Polygon
{
public:
  Point *points;
  Polygon(int n)
  {
    points = new Point[n];
  }
};

double area(Polygon p, int n)
{
  double res = 0;
  for (int i = 1; i < n - 1; i++)
  {
    double x1 = p.points[i].x - p.points[0].x;
    double y1 = p.points[i].y - p.points[0].y;
    double x2 = p.points[i + 1].x - p.points[0].x;
    double y2 = p.points[i + 1].y - p.points[0].y;

    double cp = (x1 * y2 - y1 * x2);
    res += cp;
  }

  return abs(res / 2);
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    Polygon p(n);
    for (int i = 0; i < n; i++)
    {
      cin >> p.points[i].x;
      cin >> p.points[i].y;
    }
    cout << area(p, n) << endl;
  }
  return 0;
}