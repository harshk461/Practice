#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<vector<int>> &nums)
{
    vector<int> ans;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> temp = nums[i];
        for (auto j : temp)
        {
            map[j]++;
        }
    }

    for (auto i = map.begin(); i != map.end(); i++)
    {
        if (i->second == nums.size())
        {
            ans.push_back(i->first);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 3, 5}};
    intersection(arr);
    return 0;
}