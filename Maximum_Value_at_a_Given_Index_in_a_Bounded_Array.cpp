#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long getSum(int n, int index, int x)
    {
        int l = min(index, x - 1);
        int r = min(n - index, x);
        long lSum = ((x - 1) + (x - 1 - l + 1)) * l / 2;
        long rSum = (x + (x - r + 1)) * r / 2;
        return lSum + rSum;
    }

public:
    int maxValue(int n, int index, int maxSum)
    {
        maxSum -= n;
        int l = 0;
        int r = maxSum;

        // Find the first value x s.t. if A[index] = x
        // Sum(A) >= maxSum
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (getSum(n, index, m) >= maxSum)
                r = m;
            else
                l = m + 1;
        }
        return getSum(n, index, 1) > maxSum ? l : l + 1;
    }
};

int main()
{

    return 0;
}