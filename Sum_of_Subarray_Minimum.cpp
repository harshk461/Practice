#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<long long> dp(n, -1);
        vector<int> stack;

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (!stack.empty() && arr[i] < arr[stack.back()])
                stack.pop_back();

            if (!stack.empty())
            {
                int j = stack.back();
                dp[i] = dp[j] + arr[i] * (i - j);
            }
            else
                dp[i] = arr[i] * (i + 1);

            stack.push_back(i);
            ans = (ans + dp[i]) % MOD;
        }

        return ans;
    }
};

int main()
{

    return 0;
}