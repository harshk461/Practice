#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int m = rowSum.size();
        int n = colSum.size();

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i += (rowSum[i] == 0))
        {
            for (int j = 0; j < n; j += (colSum[j] == 0))
            {
                int x = min(rowSum[i], colSum[j]);
                ans[i][j] = x;
                rowSum[i] -= x;
                colSum[j] -= x;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}