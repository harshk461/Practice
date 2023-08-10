#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int f(int index, int target, vector<int> &arr)
    {
        if (target == 0)
            return 1;

        if (index == 0)
            return arr[index] == target;

        int notTaken = f(index - 1, target, arr);
        int taken = 0;
        if (arr[index] <= target)
            taken = f(index - 1, target - arr[index], arr);

        return notTaken + taken;
    }

    int fMem(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (target == 0 && arr[0] == 0)
                return 2;
            if (target == 0 || target == arr[0])
                return 1;
            return 0;
        }

        if (dp[index][target] != -1)
            return dp[index][target];

        int notTaken = fMem(index - 1, target, arr, dp);
        int taken = 0;
        if (arr[index] <= target)
            taken = fMem(index - 1, target - arr[index], arr, dp);

        return dp[index][target] = notTaken + taken;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum - target < 0)
            return 0;
        if ((totalSum - target) % 2 == 1)
            return 0;

        int s2 = (totalSum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(s2+1, -1));
        return fMem(n - 1, s2, nums, dp);
    }
};

int main()
{

    return 0;
}