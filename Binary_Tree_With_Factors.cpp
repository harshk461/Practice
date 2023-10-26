#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long MOD = 1e9 + 7;
    long long solve(int i, unordered_set<int> &st, vector<int> &arr, unordered_map<int, long long> &dp)
    {
        if (dp.find(i) != dp.end())
            return dp[i];

        int count = 1;
        for (auto it : arr)
        {
            if (it > i)
                break;
            if (i % it == 0 && st.find(i / it) != st.end())
                count = count % MOD + (solve(i / it, st, arr, dp) * solve(it, st, arr, dp)) % MOD;
        }

        return dp[i] = count % MOD;
    }

public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> dp;
        unordered_set<int> st;
        for (auto it : arr)
            st.insert(it);

        long long ans = 0;
        for (auto it : arr)
            ans += solve(it, st, arr, dp) % MOD;

        return ans % MOD;
    }
};

int main()
{

    return 0;
}