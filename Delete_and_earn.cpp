#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        vector<int> dp(10001);
        for (int num : nums)
        {
            dp[num] += num;
        }
        int prev1 = 0;
        int prev2 = 0;

        for (int num : dp)
        {
            int temp = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }
};

int main()
{

    return 0;
}