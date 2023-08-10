#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int n, int k, int i, vector<vector<int>> &ans, vector<int> &curr)
    {
        if (curr.size() == k)
            ans.push_back(curr);

        else
        {
            for (int j = i; j <= n; j++)
            {
                curr.push_back(j);
                solve(n, k, j + 1, ans, curr);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(n, k, 1, ans, curr);
        return ans;
    }
};

int main()
{

    return 0;
}