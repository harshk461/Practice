#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TLE
    vector<int> relocateMarbles(vector<int> &nums, vector<int> &moveFrom, vector<int> &moveTo)
    {
        for (int i = 0; i < moveFrom.size(); i++)
        {
            int from = moveFrom[i];
            int to = moveTo[i];

            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] == from)
                {
                    nums[j] = to;
                }
            }
        }
        sort(nums.begin(), nums.end());
        set<int> s(nums.begin(), nums.end());
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};

vector<int> relocateMarbles(vector<int> &nums, vector<int> &moveFrom, vector<int> &moveTo)
{
    unordered_map<int, bool> map;
    for (auto num : nums)
        map[num] = true;

    for (int i = 0; i < moveFrom.size(); i++)
    {
        map[moveFrom[i]] = false;
        map[moveTo[i]] = true;
    }

    set<int> s;
    for (auto i : map)
    {
        if (i.second == true)
            s.insert(i.first);
    }
    vector<int> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    Solution s;
    vector<int> n = {1, 1, 3, 3};
    vector<int> from = {1, 3};
    vector<int> to = {2, 2};
    vector<int> ans = s.relocateMarbles(n, from, to);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}