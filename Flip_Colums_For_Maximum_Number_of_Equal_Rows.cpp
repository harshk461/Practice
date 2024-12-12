#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        int col = matrix[0].size();
        int ans = 0;

        for (auto row : matrix)
        {
            vector<int> flipped(col);
            int identical_rows = 0;

            for (int i = 0; i < col; i++)
                flipped[i] = 1 - row[i];

            // check for flipped row is present or not then count it
            for (auto it : matrix)
            {
                if (it == row || it == flipped)
                    identical_rows++;
            }

            ans = max(ans, identical_rows);
        }

        return ans;
    }
};

int main()
{

    return 0;
}