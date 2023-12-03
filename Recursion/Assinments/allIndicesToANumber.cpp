int allIndexes(int input[], int currIndex, int size, int x, int output[], int &k)
{
  if (size == 0)
  {
    return k;
  }
  if (input[currIndex] == x)
  {
    output[k] = currIndex;
    k++;
  }
  allIndexes(input, currIndex + 1, size - 1, x, output, k);
  return k;
}

int allIndexes(int input[], int size, int x, int output[])
{
  
  int k = 0;
  allIndexes(input, 0, size, x, output, k);
  return k;
}