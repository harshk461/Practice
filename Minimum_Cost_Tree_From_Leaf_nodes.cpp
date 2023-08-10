#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
    {
        // leaf node
        if (left == right)
            return 0;

        int ans = INT_MAX;
        for (int i = left; i < right; i++)
            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solve(arr, maxi, left, i) + solve(arr, maxi, i + 1, right));

        return ans;
    }

    int solveMem(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp)
    {
        // leaf node
        if (left == right)
            return 0;

        if (dp[left][right] != -1)
            return dp[left][right];

        int ans = INT_MAX;
        for (int i = left; i < right; i++)
            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solve(arr, maxi, left, i) + solve(arr, maxi, i + 1, right));

        return dp[left][right] = ans;
    }

    int solveTab(vector<int> &arr, map<pair<int, int>, int> &maxi) {
        
    }

public:
    int mctFromLeafValues(vector<int> &arr
    {
        // for storing maximum number in a range of pair of i and j
        map<pair<int, int>, int> maxi;

        for (int i = 0; i < arr.size(); i++)
        {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < arr.size(); j++)
            {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solveMem(arr, maxi, 0, n - 1, dp);
    }
};

int main()
{

    return 0;
}