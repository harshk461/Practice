#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> solve(vector<vector<int>> &nums)
    {
        unordered_map<int, vector<int>> map;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                int diagonal = i + j;
                map[diagonal].push_back(nums[i][j]);
            }
        }

        vector<int> ans;
        int curr = 0;

        while (map.find(curr) != map.end())
        {
            for (auto it : map[curr])
                ans.push_back(num);
            curr++;
        }

        return ans;
    }

public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        int i = 0;
        unordered_map<int, list<int>> map;
        int n = nums.size();
        while (i < n)
        {
            vector<int> temp = nums[i];
            for (int j = 0; j < temp.size(); j++)
            {
                int sum = i + j;
                map[sum].push_back(nums[i][j]);
            }
            i++;
        }

        vector<int> ans;

        for (auto it : map)
        {
            vector<int> temp = it.second;
            reverse(temp.begin(), temp.end());
            for (auto i : temp)
                ans.push_back(i);
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4, 5}, {6, 7}, {8}, {9, 10, 11}, {12, 13, 14, 15, 16}};
    Solution s;
    s.findDiagonalOrder(arr);
    return 0;
}