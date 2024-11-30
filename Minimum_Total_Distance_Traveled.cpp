#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false); // Speeds up the I/O operations by decoupling C++ standard streams from C standard streams
    cin.tie(0);                  // Unties cin and cout, which slightly improves input/output speed
    cout.tie(0);                 // Unties cout from cin for faster output
    return 'c';                  // Dummy return to allow the lambda to run on startup
}();

class Solution
{
public:
    // Recursive helper function with memoization to calculate the minimum total distance.
    // Parameters:
    //   i: Index of the current robot.
    //   j: Index of the current factory.
    //   robot: Vector containing positions of robots.
    //   factory: 2D vector where each element is [position, maxCapacity] for a factory.
    //   dp: 2D memoization table to store minimum distance results for subproblems.
    long long solve(int i, int j, vector<int> &robot, vector<vector<int>> &factory, vector<vector<long long>> &dp)
    {
        // Base case 1: No robots left to process
        if (i < 0)
            return 0;

        // Base case 2: No factories left, so return a large number to indicate infeasibility
        if (j < 0)
            return 1e15;

        // Return precomputed result if available
        if (dp[i][j] != -1)
            return dp[i][j];

        // Initialize minimum distance as a large number
        long long minDist = 1e15;

        // Option 1: Skip the current factory and continue with the remaining factories
        minDist = solve(i, j - 1, robot, factory, dp);

        // Option 2: Assign robots to the current factory up to its capacity limit
        long long totalDist = 0;
        for (int k = 0; k < factory[j][1] && i - k >= 0; ++k)
        {
            // Calculate distance for assigning robot[i - k] to factory[j]
            totalDist += abs(robot[i - k] - factory[j][0]);

            // If total distance exceeds a large threshold, stop further calculations for efficiency
            if (totalDist >= 1e15)
                break;

            // Update minimum distance by recursively processing remaining robots and factories
            minDist = min(minDist, totalDist + solve(i - k - 1, j - 1, robot, factory, dp));
        }

        // Store the computed minimum distance for this subproblem
        dp[i][j] = minDist;
        return dp[i][j];
    }

    // Main function to calculate the minimum total distance
    // Parameters:
    //   robot: Vector of robot positions.
    //   factory: 2D vector where each element is [position, maxCapacity] representing factories.
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        int m = robot.size();   // Number of robots
        int n = factory.size(); // Number of factories

        // Sort robot positions to align them in increasing order
        sort(robot.begin(), robot.end());

        // Sort factories based on their positions to match robots more efficiently
        sort(factory.begin(), factory.end());

        // Initialize memoization table with -1 to indicate uncalculated subproblems
        vector<vector<long long>> dp(m, vector<long long>(n, -1));

        // Start recursive solution from the last robot and last factory
        return solve(m - 1, n - 1, robot, factory, dp);
    }
};

int main()
{

    return 0;
}