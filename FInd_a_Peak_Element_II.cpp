#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isPeak(vector<vector<int>> &mat, int row, int col)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dirn = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1},
        };

        for (auto it : dirn)
        {
            int x = row + it[0];
            int y = col + it[1];
            if (x >= 0 && y >= 0 && x < m && y < n && mat[x][y] > mat[row][col])
                return false;
        }
        return true;
    }

public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isPeak(mat, i, j))
                    return {i, j};
            }
        }
        return {-1, -1};
    }
};

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int maxRow = 0;
            int midCol = low + (high - low) / 2;
            for (int row = 0; row < m; row++)
                if (mat[row][midCol] > mat[maxRow][midCol])
                    maxRow = row;

            int currE = mat[maxRow][midCol];
            int leftE = midCol == 0 ? -1 : mat[maxRow][midCol - 1];
            int rightE = midCol == n - 1 ? -1 : mat[maxRow][midCol + 1];

            if (currE > leftE && currE > rightE)
                return {maxRow, midCol};
            else if (currE < leftE)
                high = midCol - 1;
            else
                low = midCol + 1;
        }
    }
};

int main()
{

    return 0;
}