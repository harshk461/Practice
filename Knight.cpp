#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Possible moves of a knight
    vector<pair<int, int>> dirn = {
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

    vector<vector<int>> ans;
    vector<pair<int, int>> curr;

public:
    bool isSafe(int x, int y, vector<vector<int>> &board)
    {
        return (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == -1);
    }

    bool isPossible(int x, int y, int moveCount, vector<vector<int>> &board)
    {
        if (moveCount == 64)
            return true;

        for (auto &d : dirn)
        {
            int newX = x + d.first;
            int newY = y + d.second;

            if (isSafe(newX, newY, board))
            {
                board[newX][newY] = moveCount;
                if (isPossible(newX, newY, moveCount + 1, board))
                    return true;
                board[newX][newY] = -1; // Backtrack
            }
        }
        return false;
    }

    void solve()
    {
        vector<vector<int>> board(8, vector<int>(8, -1));
        board[0][0] = 0;
        if (isPossible(0, 0, 1, board))
            print(board);
        else
            cout << "No solution exists" << endl;
    }

    void print(vector<vector<int>> &board)
    {
        for (auto &row : board)
        {
            for (auto &cell : row)
                cout << setw(2) << cell << " ";
            cout << endl;
        }
    }
};

int main()
{
    Solution s;
    s.solve();
    return 0;
}
