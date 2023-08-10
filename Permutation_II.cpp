#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int index, vector<int> &nums, set<vector<int>> &ans)
    {
        if (index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(index+1,nums,ans);
            swap(nums[index],nums[i]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        set<vector<int>> ans;
        int index = 0;
        solve(index, nums, ans);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};

int main()
{

    return 0;
}