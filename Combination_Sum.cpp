#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(vector<int> &arr, int index, int target, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (index == arr.size())
        {
            if (target == 0)
                ans.push_back(ds);
            return;
        }

        // include element;
        if (arr[index] <= target)
        {
            ds.push_back(arr[index]);
            solve(arr, index, target - arr[index], ans, ds);
            ds.pop_back();
        }

        // exclude element
        solve(arr, index + 1, target, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(candidates, 0, target, ans, ds);
        return ans;
    }
};

int main()
{

    return 0;
}