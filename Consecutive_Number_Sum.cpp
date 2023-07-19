#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TLE
    int consecutiveNumbersSum(int n)
    {
        long int sum = 0;
        int ctr = 1;
        if (n == 1 || n == 2)
            return 1;
        for (int i = 1; i < n / 2 + 1; i++)
        {
            for (int j = i; j <= n / 2 + 2; j++)
            {
                if (sum < n)
                {
                    sum += j;
                }
                else
                {
                    if (sum == n)
                        ctr++;
                    sum = 0;
                    break;
                }
            }
        }
        return ctr;
    }

    int consecutiveNumbersSum(int n) {}
};

int main()
{

    return 0;
}