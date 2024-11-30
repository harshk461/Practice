#include <bits/stdc++.h>
using namespace std;

// #pragma GCC target("avx, mmx, sse2, sse3, sse4")

// static const int disableSync = [](void) noexcept -> int
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     return 0;
// }();

class Solution
{
public:
    vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
    {
        vector<int> dp(n, 1);
        // this hash vector will store the last index which helps in making it increasing subsequence
        vector<int> hash(n);
        int maxLength = 0;
        int lastIndex = 0; // this index stores the last index of the LIS
        for (int i = 1; i < n; i++)
        {
            hash[i] = i; // initially current index make itself increasing
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[prev] < arr[i] && dp[i] < 1 + dp[prev])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }

            // if we get a longer LIS than the current maxlength
            // then we increase the maxLength and change the lastIndex to the current index
            if (dp[i] > maxLength)
            {
                maxLength = dp[i];
                lastIndex = i;
            }
        }

        // this will store the LIS
        vector<int> store;
        store.push_back(arr[lastIndex]);

        // we will iterate th hash until we reach the starting point of the hash when hash[i] =i
        while (hash[lastIndex] != lastIndex)
        {
            int val = arr[hash[lastIndex]];
            lastIndex = hash[lastIndex];
            store.push_back(val);
        }
        reverse(store.begin(), store.end());
        // for (auto it : store)
        //     cout << it << " ";
        return store;
    }
};

int main()
{
    vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    Solution s;
    s.longestIncreasingSubsequence(16, arr);
    return 0;
}