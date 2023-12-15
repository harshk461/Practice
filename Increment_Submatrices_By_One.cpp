#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> solve(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> S(n, vector<int>(n, 0));

        for (auto query : queries)
        {
            int row1 = query[0];
            int col1 = query[1];
            int row2 = query[2];
            int col2 = query[3];

            for (int i = row1; i <= row2; i++)
            {
                S[i][col1]++;
                if (col2 + 1 < n)
                    S[i][col2 + 1]--;
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
                S[i][j] = S[i][j] + S[i][j - 1];
        return S;
    }

public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
    {
        // vector<vector<int>> mat(n, vector<int>(n, 0));
        // for (auto query : queries)
        // {
        //     int row1 = query[0];
        //     int col1 = query[1];
        //     int row2 = query[2];
        //     int col2 = query[3];

        //     for (int i = row1; i < col1; i++)
        //     {
        //         for (int j = row2; j < col2; j++)
        //             mat[i][j]++;
        //     }
        // }

        return solve(n, queries);
    }
};

int main()
{
    vector<vector<int>> qr = {{1, 1, 2, 2}, {0, 0, 1, 1}};
    Solution s;
    vector<vector<int>> ans = s.rangeAddQueries(3, qr);

    for (auto it : ans)
    {
        for (auto j : it)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}