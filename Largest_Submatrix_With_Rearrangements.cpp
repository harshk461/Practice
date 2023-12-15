#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (matrix[i][j] != 0 && i > 0)
                    matrix[i][j] += matrix[i - 1][j];

            vector<int> curr = matrix[i];
            sort(curr.begin(), curr.end(), greater());
            for (int k = 0; k < n; k++)
                ans = max(ans, curr[k] * (k + 1));
        }

        return ans;
    }
};

int main()
{

    return 0;
}