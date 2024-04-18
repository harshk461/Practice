#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int mini = -1, maxi = -1, left = -1, right = 0;
        long long count = 0;

        while (right < nums.size())
        {
            if (nums[right] < minK || nums[right] > maxK)
            {
                mini = right;
                maxi = right;
                left = right;
            }
            mini = nums[right] == minK ? right : mini;
            maxi = nums[right] == maxK ? right : maxi;

            count += min(mini, maxi) - left;
            right++;
        }

        return count;
    }
};

int main()
{

    return 0;
}