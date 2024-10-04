#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
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

    int brute(int days, vector<vector<int>> &meetings)
    {
        meetings = mergeIntervals(meetings);
        vector<int> arr(days + 1, 0);
        for (auto it : meetings)
        {
            int a = it[0];
            int b = it[1];
            for (int i = a; i <= b; i++)
                arr[i] = 1;
        }

        int sum = accumulate(arr.begin(), arr.end(), 0);
        int n = arr.size() - 1;

        return n - sum;
    }

public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        meetings = mergeIntervals(meetings);
        int n = meetings.size();
        // for (auto it : meetings)
        // {
        //     cout << it[0] << " " << it[1] << endl;
        // }
        
        int ans = (meetings[0][0] - 1);
        for (int i = 0; i < meetings.size() - 1; i++)
            ans += (meetings[i + 1][0] - meetings[i][1]) - 1;

        ans += (days - meetings[n - 1][1]);
        return ans;
    }
};

int main()
{

    return 0;
}