#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int mini = INT_MAX;
        int n = arr.size();

        vector<vector<int>> ans;

        for (int i = 0; i + 1 < n; i++)
        {
            int diff = arr[i + 1] - arr[i];
            if (diff < min)
            {
                min = diff;
                ans.clear();
            }

            if (diff = min)
                ans.push_back({arr[i], arr[i + 1]});
        }

        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 3, 6, 10, 15};
    Solution s;
    s.minimumAbsDifference(arr);
    return 0;
}