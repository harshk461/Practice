#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        set<int> s(nums.begin(), nums.end());
        vector<int> arr(s.begin(), s.end());
        sort(arr.begin(), arr.end());
        if (arr.size() < 3)
            return arr[arr.size() - 1];
        return arr[arr.size() - 3];
    }
};

class Solution
{
public:
    void twosum(vector<int> &nums, int sum, vector<int> &oppsum, int curr)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == curr)
            {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j == curr)
                {
                    continue;
                }
                if (nums[i] + nums[j] == sum)
                {
                    oppsum.push_back(nums[i]);
                    oppsum.push_back(nums[j]);
                    return;
                }
            }
        }
        return;
    }
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> oppsum;
            int firstnum = nums[i];
            twosum(nums, -firstnum, oppsum, i);
            if (oppsum.size() != 0)
            {
                oppsum.push_back(firstnum);
                ans.push_back(oppsum);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}