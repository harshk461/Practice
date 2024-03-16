#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxArrayValue(vector<int> &nums)
    {
        long long ans = 0;
        long long sum = 0;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (sum >= nums[i])
                sum += nums[i];
            else
                sum = nums[i];

            ans = max(ans, sum);
        }

        return ans;
    }
};

int main()
{

    return 0;
}