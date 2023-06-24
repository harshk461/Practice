#include <bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
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

void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    // base case
    if (col == n)
    {
        addSolution(board, ans, n);
        return;
    }

    // one case
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, ans, n))
        {
            // if safe
            board[row][col] = 1;
            solve(col + 1, board, ans, n);
            // backtrack
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n));
    vector<vector<int>> ans(n);

    solve(0, board, ans, n);

    return ans;
}

int main()
{

    return 0;
}