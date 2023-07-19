#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void markRow(vector<vector<int>> &arr, int i, int m)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != 0)
                arr[i][j] = -1;
        }
    }

    void markCol(vector<vector<int>> &arr, int i, int m)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[j][i] != 0)
                arr[j][i] = -1;
        }
    }

public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    markRow(matrix, i, n);
                    markCol(matrix, j, m);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// another method O(N*M) SC-O(N+M)
void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> col(m, 0);
    vector<int> row(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 1 || col[j] == 1)
                matrix[i][j] = 0;
        }
    }
}

// optimal method
void setZeroes2(vector<vector<int>> &matrix)
{
    int col0 = 1;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark i-th row
                matrix[i][0] = 0;
                // mark j-th col
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                // check row and col
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[0][i] = 0;
        }
    }

    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    Solution s;
    vector<vector<int>> mat = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setZeroes(mat);
    for (auto i : mat)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}