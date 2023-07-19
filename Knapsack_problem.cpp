#include <bits/stdc++.h>
using namespace std;

// Recursion and TLE
int solve(vector<int> &weight, vector<int> &value, int index, int capacity)
{
    // base case
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);

    int exclude = 0 + solve(weight, value, index - 1, capacity);

    int ans = max(include, exclude);
    return ans;
}

// Recursion and Memoization Top Down
int solveMem(vector<int> &weight, vector<int> &value, int index,
             int capacity, vector<vector<int>> &dp)
{
    // base case
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);

    int exclude = 0 + solve(weight, value, index - 1, capacity);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int solveMem(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    // step 1 create dp array
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // step 2 analyse base case
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (weight[index] <= w)
                include = value[index] + dp[index - 1][capacity - weight[index]];

            int exclude = 0 + dp[index - 1][capacity];

            dp[index][capacity] = max(include, exclude);
        }
    }
    return dp[n - 1][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
}

int main()
{

    return 0;
}