class Solution
{
public:
  vector<int> singleNumber(vector<int> &nums)
  {
    long long resultantXor = 0;
    for (int &num : nums)
    {
      resultantXor ^= num;
    }
    long long setBit = resultantXor & (~(resultantXor - 1));
    long long x = resultantXor;
    long long y = resultantXor;
    for (int &num : nums)
    {
      if (num & setBit)
      {
        x ^= num;
      }
      else
      {
        y ^= num;
      }
    }
    vector<int> v;
    v.push_back(x);
    v.push_back(y);
    return v;
  }
};