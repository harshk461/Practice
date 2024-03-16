#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;

        for (int left = 0; left < m; left++)
        {
            vector<int> pre(n, 0);
            for (int right = left; right < m; right++)
            {
                for (int i = 0; i < n; i++)
                    pre[i] += matrix[i][right];

                for (int i = 0; i < n; i++)
                {
                    int sum = 0;
                    for (int j = i; j < n; j++)
                    {
                        sum += pre[j];
                        if (sum == target)
                            ans++;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> mat = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
    Solution s;
    s.numSubmatrixSumTarget(mat, 0);
    return 0;
}