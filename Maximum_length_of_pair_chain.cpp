#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        // sort(pairs.begin(), pairs.end(), [&](vector<int> &a, vector<int> &b)
        //      { return a[0] < b[0]; });
        // int i, j, max_len = 0;
        // int n = pairs.size();
        // vector<int> length(n, 1);

        // for (int i = 1; i < n; i++)
        //     for (int j = 0; j < i; j++)
        //         if (pairs[i][0] > pairs[j][1] && (length[i] < length[j] + 1))
        //             length[i] = length[j] + 1;

        // for (int i = 0; i < n; i++)
        //     if (max_len < length[i])
        //         max_len = length[i];

        // return max_len;

        int ans = 0;
        int prevEnd = INT_MIN;
        sort(pairs.begin(), pairs.end(), [&](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });

        for (auto pair : pairs)
        {
            if (pair[0] > prevEnd)
            {
                ans++;
                prevEnd = pair[1];
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}