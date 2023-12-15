#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int val)
{
    for (int i = 0; i < board.size(); i++)
    {
        // row check
        if (board[row][i] == val)
        {
            return false;
        }
        // col check
        if (board[i][col] == val)
        {
            return false;
        }
        // 3*3 matrix check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &board)
{
    int n = board[0].size();
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {

            if (board[row][col] == 0)
            {
                for (int i = 1; i <= 9; i++)
                {
                    if (isSafe(row, col, board, i))
                    {
                        board[row][col] = i;

                        bool nextSoln = solve(board);
                        if (nextSoln)
                        {
                            return true;
                        }
                        else
                        {
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}

int main()
{
    vector<vector<int>> board = {{0, 6, 0, 2, 8, 0, 3, 4, 9},
                                 {0, 0, 8, 6, 0, 3, 0, 0, 0},
                                 {0, 2, 3, 9, 0, 0, 6, 0, 8},
                                 {0, 1, 0, 7, 6, 9, 0, 0, 3},
                                 {0, 0, 6, 4, 3, 2, 7, 0, 0},
                                 {3, 0, 0, 5, 1, 8, 0, 9, 6},
                                 {7, 3, 9, 8, 2, 6, 1, 5, 4},
                                 {6, 8, 4, 1, 7, 5, 9, 3, 2},
                                 {2, 5, 1, 3, 9, 4, 8, 6, 7}};
    solveSudoku(board);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}