#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isSafe(int row, int col, vector<vector<int>> &board)
    {
        int n = board.size();
        int x = row;
        int y = col;

        // check same row
        while (y >= 0)
        {
            if (board[x][y] == 1)
            {
                return false;
            }
            y--;
        }

        x = row;
        y = col;
        // check uper diagonal
        while (x >= 0 && y >= 0)
        {
            if (board[x][y] == 1)
            {
                return false;
            }
            x--;
            y--;
        }

        x = row;
        y = col;
        // check lower diagonal
        while (x < n && y >= 0)
        {
            if (board[x][y] == 1)
            {
                return false;
            }
            x++;
            y--;
        }

        return true;
    }

    void solve(int col, vector<vector<int>> &board, int &ans)
    {
        int n = board.size();
        if (col == n)
        {
            ans++;
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board))
            {
                board[row][col] = 1;
                solve(col + 1, board, ans);
                board[row][col] = 0;
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        vector<vector<int>> board(n, vector<int>(n, 0));
        int ans = 0;
        solve(0, board, ans);
        return ans;
    }
};

int main()
{

    return 0;
}