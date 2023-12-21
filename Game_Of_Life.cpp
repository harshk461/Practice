#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> dirn = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0},
            {-1, 1},
            {1, 1},
            {-1, -1},
            {1, -1},
        };
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> change_one_posn;
        vector<vector<int>> change_zero_posn;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // check if dead cell have exactly 3 live nbr
                if (board[i][j] == 0)
                {
                    int liveNbr = 0;
                    for (auto it : dirn)
                    {
                        int x = i + it[0];
                        int y = j + it[1];
                        if (x < m && y < n && x >= 0 && y >= 0)
                        {
                            if (board[x][y] == 1)
                                liveNbr++;
                        }
                    }
                    if (liveNbr == 3)
                        change_one_posn.push_back({i, j});
                }
                else
                {
                    // check if any live nbr have more than 3 live nbr
                    int liveNbr = 0;
                    for (auto it : dirn)
                    {
                        int x = i + it[0];
                        int y = j + it[1];
                        if (x < m && y < n && x >= 0 && y >= 0)
                        {
                            if (board[x][y] == 1)
                                liveNbr++;
                        }
                    }
                    if (liveNbr == 2 || liveNbr == 3)
                        change_one_posn.push_back({i, j});

                    if (liveNbr < 2 || liveNbr > 3)
                        change_zero_posn.push_back({i, j});
                }
            }
        }

        for (auto it : change_zero_posn)
            board[it[0]][it[1]] = 0;
        for (auto it : change_one_posn)
            board[it[0]][it[1]] = 1;
    }
};

int main()
{
    vector<vector<int>> arr = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    Solution s;
    s.gameOfLife(arr);
    for (auto it : arr)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}