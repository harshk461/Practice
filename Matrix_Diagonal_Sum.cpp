#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int sum = 0;
        // diagonal 1
        for (int i = 0; i < n; i++)
            sum += mat[i][i];

        // diagonal 2
        for (int i = 0; i < n; i++)
            if (i != n - 1 - 1)
                sum += mat[i][n - 1 - i];
        return sum;
    }
};

int main()
{

    return 0;
}