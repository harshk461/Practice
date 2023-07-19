#include <bits/stdc++.h>
using namespace std;

class Solution
{
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