#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;

        while (i < n && intervals[i][1] < newInterval[0])
            ans.push_back(intervals[i++]);
        // merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        while (i < n)
        {
            ans.push_back(intervals[i++]);
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 3}, {6, 9}};
    vector<int> a1 = {2, 5};
    Solution s;
    vector<vector<int>> ans = s.insert(arr, a1);
    for (auto i : ans)
        for (auto j : i)
            cout << j << " ";
    cout << endl;
    return 0;
}