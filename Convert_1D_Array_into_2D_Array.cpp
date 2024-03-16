#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        if (m * n != original.size())
            return {};

        vector<vector<int>> mat(m, vector<int>(n, 0));
        int idx = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = original[idx++];
        return mat;
    }
};

int main()
{

    return 0;
}