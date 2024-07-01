int maxHeightOfTriangle(int red, int blue)
{
  int h = 0;
  int r = red;
  int b = blue;
  bool redVal = true;
  int i = 1;
  int j = 2;
  while (true)
  {
    if (redVal)
    {
      if (red >= i)
        red = red - i;
      else
      {
        break;
      }
      i += 2;
      redVal ^= redVal;
      h++;
    }
    else
    {
      if (blue >= j)
      {
        blue = blue - j;
      }
      else
      {
        break;
      }
      j += 2;
      h++;
    }
  }
  int h1 = h;
  h = 0;
  i = 1;
  j = 2;
  int blueVal = true;
  red = r;
  blue = b;
  while (true)
  {
    if (blueVal)
    {
      if (blue >= i)
        blue = blue - i;
      else
      {
        break;
      }
      i += 2;
      blueVal ^= blueVal;
      h++;
    }
    else
    {
      if (red >= j)
      {
        red = red - j;
      }
      else
      {
        break;
      }
      j += 2;
      h++;
    }
  }
  cout << red << " " << blue << endl;

  cout << h1 << " " << h << endl;
  return max(h1, h);
}