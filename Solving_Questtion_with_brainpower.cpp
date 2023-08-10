#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long solve(int index, vector<vector<int>> &questions, vector<long long> &dp)
    {
        if (index >= questions.size())
            return 0;

        if (dp[index] != -1)
            return dp[index];

        // include
        long long include = questions[index][0] + solve(index + questions[index][1] + 1, questions, dp);

        // exclude
        long long exclude = solve(index + 1, questions, dp);

        return dp[index] = max(include, exclude);
    }

    long long solveTab(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            int points = questions[index][0];
            int next = questions[index][1];
            int nextIndex = index + next + 1;

            long long include = 0;
            if (nextIndex < n)
                include = points + dp[nextIndex];
            long long exclude = dp[index + 1];

            dp[index] = max(include, exclude);
        }

        return dp[0];
    }

    long long solve2(vector<vector<int>> &questions)
    {
        const int n = questions.size();
        vector<long long> dp(n + 1);

        for (int i = n - 1; i >= 0; --i)
        {
            const int points = questions[i][0];
            const int brainpower = questions[i][1];
            const int nextIndex = i + brainpower + 1;
            const long long nextPoints = nextIndex < n ? dp[nextIndex] : 0;
            dp[i] = max(points + nextPoints, dp[i + 1]);
        }

        return dp[0];
    }

public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        // long long n = questions.size();
        // vector<long long> dp(n + 1, -1);
        // return solve(0, questions, dp);
        return solve2(questions);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> arr = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    cout << s.mostPoints(arr);
    return 0;
}