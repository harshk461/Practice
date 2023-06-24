#include <bits/stdc++.h>
using namespace std;

vector<int> leftRightDifference(vector<int> &nums)
{
    int leftSum = 0;
    int rightSum = 0;
    vector<int> left;
    vector<int> right;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        left.push_back(leftSum);
        leftSum += nums[i];
    }

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        right.push_back(rightSum);
        rightSum += nums[i];
    }
    reverse(right.begin(), right.end());
    for (int i = 0; i < nums.size(); i++)
    {
        ans.push_back(abs(left[i] - right[i]));
    }
    return ans;
}
int main()
{
    vector<int> nums = {10, 4, 8, 3};
    leftRightDifference(nums);
    return 0;
}