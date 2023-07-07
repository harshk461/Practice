#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isSafe(vector<vector<char>> &board, int row, int col, int val)
    {
        for (int i = 0; i < board.size(); i++)
        {
            // row check
            if (board[row][i] == (val + '0'))
                return false;
            // col check
            if (board[i][col] == (val + '0'))
                return false;
            // 3*3 matrix check
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == (val + '0'))
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        int n = board[0].size();
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (board[row][col] == '.')
                {
                    for (int i = 1; i <= 9; i++)
                    {
                        if (isSafe(board, row, col, i))
                        {
                            board[row][col] = i + '0';

                            bool nextSoln = solve(board);
                            if (nextSoln)
                            {
                                return true;
                            }
                            else
                            {
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};
int main()
{
    if ('.' == '.')
        cout << "eys";
    else
        cout << "no";
    return 0;
}