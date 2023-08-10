#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solveOptimal(vector<int> &arr)
    {
        if (n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(a[0]);

        for (int i = 1; i < n; i++)
        {
            if (a[i] > ans.back())
                ans.push_back(a[i]);
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }

public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), [&](vector<int> &a, vector<int> &b)
             {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                     else 
                     return a[0]<b[0]; });
        vector<int> height;
        for (auto i : envelopes)
            height.push_back(i[1]);

        return solveOptimal(height);
    }
};

int main()
{
    vector<vector<int>> arr = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    Solution s;
    s.maxEnvelopes(arr);
    return 0;
}