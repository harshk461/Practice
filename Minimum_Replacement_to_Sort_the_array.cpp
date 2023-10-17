#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        long long ans = 0;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] <= nums[i + 1])
                continue;

            long long numE = ceil((nums[i] + nums[i + 1] - 1LL) / (nums[i + 1]));

            ans += numE - 1;
            nums[i] = nums[i] / numE;
        }
        return ans;
    }
};

int main()
{

    return 0;
}