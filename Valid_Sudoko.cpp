#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(vector<vector<char>> &board)
    {
        // row and col check
        for (int i = 0; i < 9; i++)
        {
            unordered_map<int, int> row;
            unordered_map<int, int> col;
            unordered_map<int, int> mat;
            for (int j = 0; j < 9; j++)
            {
                // row check
                if (board[i][j] != '\0' && row[board[i][j] - 'a'])
                {
                    return false;
                }
                else
                {
                    row[board[i][j] - 'a'] = 1;
                }

                // row check
                if (board[j][i] != '\0' && col[board[j][i] - 'a'])
                {
                    return false;
                }
                else
                {
                    col[board[i][j] - 'a'] = 1;
                }

                if (board[3 * (i / 3) + i / 3][3 * (j / 3) + i % 3] != '\0' &&
                    mat[board[3 * (i / 3) + i / 3][3 * (j / 3) + i % 3]])
                {
                    return false;
                }
                else
                {
                    board[3 * (i / 3) + i / 3][3 * (j / 3) + i % 3] = 1;
                }
            }
            row.clear();
            col.clear();
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        return solve(board);
    }
};

int main()
{
    return 0;
}