#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        vector<int> ans;
        int left = -1, right = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                left = i;
                break;
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] == target)
            {
                right = i;
                break;
            }
        }
        return {left, right};
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (l == nums.size() || nums[l] != target)
        {
            return {-1, -1};
        }
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {l, r};
    }
};

int main()
{
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    Solution s;
    vector<int> ans = s.searchRange(arr, 6);
    for (auto i : ans)
        cout << i << ' ';
    return 0;
}