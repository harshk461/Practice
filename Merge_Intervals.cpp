#include <bits/stdc++.h>
using namespace std;

// brute force TC-O(NLogn)+O(2N)
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < n; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

// optimised method TC-O(NLogN)+O(N) SC-O(N)
vector<vector<int>> merge2(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || ans.back()[1] < intervals[i][0])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr = {{1, 3}, {6, 9}};
    vector<vector<int>> ans = merge2(arr);
    for (auto i : ans)
        for (auto j : i)
            cout << j << " ";
    cout << endl;
    return 0;
}