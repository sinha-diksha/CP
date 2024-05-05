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

long area(Polygon p, int n)
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

  return (long)abs(res / 2);
}

int main()
{
  string s;
  cin >> s;
  int n = s.length();
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  Polygon p(n);
  int curx = 0;
  int cury = 0;
  p.points[0].x = curx;
  p.points[0].y = cury;
  for (int i = 0; i < n - 1; i++)
  {
    if (s[i] == 'N')
    {
      cury += v[i];
    }
    else if (s[i] == 'S')
    {
      cury -= v[i];
    }
    else if (s[i] == 'W')
    {
      curx -= v[i];
    }
    else
    {
      curx += v[i];
    }
    p.points[i + 1].x = curx;
    p.points[i + 1].y = cury;
  }
  cout << area(p, n) << endl;

  return 0;
}