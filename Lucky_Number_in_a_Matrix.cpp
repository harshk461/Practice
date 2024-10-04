#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;
        vector<int> row_min(m, 0);
        vector<int> col_max(n, 0);

        for (int i = 0; i < m; i++)
            row_min[i] = *min_element(matrix[i].begin(), matrix[i].end());

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                col_max[i] = max(col_max, matrix[j][i]);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row_min[i] == col_max[j])
                    ans.push_back(matrix[i][j]);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}