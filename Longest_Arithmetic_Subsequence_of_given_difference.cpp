#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &arr, int difference)
    {
        unordered_map<int, int> dp;
        int ans = 0;
        for (int i = 0; i < arr.size(), i++)
        {
            int temp = arr[i] - difference;
            int tempAns = 0;

            // check if answer is already present
            if (dp.count(temp))
                tempAns = dp[temp];

            // current answer update
            dp[arr[i]] = 1 + tempAns;

            // update ans
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }

public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        // int n = arr.size();
        // unordered_map<int, int> map;
        // int ans = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     int x = arr[i];
        //     map[x] = 1 + map[x - difference];
        //     ans = max(ans, map[x]);
        // }
        // return ans;
        // DP
        int n = arr.size();
        unordered_map<int, int> prevIndex;
        vector<int> dp(n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int prevNum = arr[i] - difference;
            if (prevIndex.count(prevNum))
                dp[i] = dp[prevIndex[prevNum]] + 1;
            else
                dp[i] = 1;
            prevIndex[arr[i]] = 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}