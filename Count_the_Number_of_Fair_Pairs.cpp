#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        return countPairs(nums, upper) - countPairs(nums, lower - 1);
    }

private:
    long long countPairs(vector<int> &nums, int target)
    {
        long long count = 0;
        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            if (nums[left] + nums[right] > target)
                right--;
            else
            {
                count += right - left;
                left++;
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}