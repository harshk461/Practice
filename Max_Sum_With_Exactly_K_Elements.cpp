#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximizeSum(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int maxNum = nums[nums.size() - 1];
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            ans += maxNum;
            maxNum++;
        }
        return ans;
    }
};
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    cout << maximizeSum(nums, 3);
    return 0;
}