#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int i, int n, int k, vector<vector<int>> &ans, vector<int> &curr)
    {
        if (curr.size() == k && n == 0)
        {
            ans.push_back(curr);
            return;
        }

        if (curr.size() == k && n != 0)
            return;

        for (int j = i; j < 9; j++)
        {
            curr.push_back(j);
            solve(j + 1, n - j, ans, curr);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1, n, k, ans, curr);
        return ans;
    }
};

int main()
{

    return 0;
}