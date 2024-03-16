#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(int index, vector<int> &arr, vector<int> &vis, vector<int> &dp)
    {
        if (index >= arr.size() || index < 0)
            return false;
        if (dp[index] != -1)
            return dp[index];

        if (vis[index])
            return false;

        if (arr[index] == 0)
            return true;
        vis[index] = 1;
        return dp[index] = solve(index + arr[index], arr, vis) || solve(index - arr[index], arr, vis);
    }

public:
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        vector<int> vis(n, 0);
        vector<int> dp(n, -1);
        return solve(start, arr, vis, dp);
    }
};

int main()
{

    return 0;
}