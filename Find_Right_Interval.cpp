#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> brute(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            bool found = false;
            int mini = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    if (intervals[j][0] >= intervals[i][1] && intervals[j][0] < mini)
                    {
                        mini = intervals[j][0];
                        found = true;
                        ans[i] = j;
                    }
                }
            }
            if (!found)
                ans[i] = -1;
        }

        return ans;
    }

    vector<int> solve(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<int> ans, v;
        // start->index
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            v.push_back(intervals[i][0]);
            mp[intervals[i][0]] = i;
        }

        // V hold all start value in sorted way
        sort(v.begin(), v.end());

        for (auto it : intervals)
        {
            int lb = lower_bound(v.begin(), v.end(), it[1]) - v.begin();
            if (lb == intervals.size())
                ans.push_back(-1);
            else
                ans.push_back(mp[v[lb]]);
        }

        return ans;
    }

public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        return solve(intervals);
    }
};

int main()
{
    vector<vector<int>> arr = {{3, 4}, {2, 3}, {1, 2}};
    Solution s;
    vector<int> ans = s.findRightInterval(arr);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}