#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // TLE
    void solve(vector<int> &arr, set<vector<int>> &ans, vector<int> &curr, int index, int target)
    {
        if (index == arr.size())
        {
            if (target == 0)
            {
                sort(curr.begin(), curr.end());
                ans.insert(curr);
            }
            return;
        }

        // include element;
        if (arr[index] <= target)
        {
            curr.push_back(arr[index]);
            solve(arr, ans, curr, index + 1, target - arr[index]);
            curr.pop_back();
        }

        solve(arr, ans, curr, index + 1, target);
    }

    void dfs(vector<int> &arr, int s, int target, vector<int> path, vector<vector<int>> &ans)
    {
        if (target < 0)
            return;

        if (target == 0)
        {
            ans.push_back(path);
            return;
        }

        for (int i = s; i < arr.size(); i++)
        {
            if (i > s && arr[i] == arr[i - 1])
                continue;

            path.push_back(arr[i]);
            dfs(arr, i + 1, target - arr[i], path, ans);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, curr, ans);
        return ans;
    }
};

int main()
{

    return 0;
}