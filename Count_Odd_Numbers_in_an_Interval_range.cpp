#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int low, int high)
    {
        if (low == high)
        {
            if (low % 2 != 0)
                return 1;
            return 0;
        }

        if (low % 2 == 0 && high % 2 == 0)
            return (high - low) / 2;

        else if (low % 2 == 1 ^ ^high % 2 == 1)
            return (high - low) / 2 + 1;
        else
            return (high - low + 1) / 2;
    }

    int solve2(int low, int high)
    {
        int ans = (high - low) / 2;
        if (high % 2 == 0 && low % 2 == 0)
            return ans;
        return ans + 1;
    }

public:
    int countOdds(int low, int high)
    {
        int count = 0;

        for (int i = low; i <= high; i++)
            if (i % 2 != 0)
                count++;

        return count;
    }
};

int main()
{

    return 0;
}