#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    int n = nums.size();
    for (auto i : nums)
    {
        map[i]++;
    }
    vector<vector<int>> ans;
    set<vector<int>> temp_ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = j; k < n; k++)
            {
                int d = target - (nums[i] + nums[j] + nums[k]);
                vector<int> temp(4);
                --nums[i];
                --nums[j];
                --nums[k];
                if (map[d] > 0 && i!=j && j!=k && i!=k)
                {
                    temp[0] = nums[i], temp[1] = nums[j], temp[2] = nums[k], temp[3] = d;
                    temp_ans.push_back(temp);
                }
            }
        }
    }

    for(auto i:temp_ans){
        ans.push_back(i);
    }
    return ans;
}

int main()
{

    return 0;
}