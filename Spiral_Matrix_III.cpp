#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        int i = rStart;
        int j = cStart;

        int dirn_i = 0;
        int dirn_j = 1;

        int twice = 2;
        vector<vector<int>> ans;
        int moves = 1;
        int next_moves = 2;

        while (ans.size() < rows * cols)
        {
            if (i >= 0 && i < rows && j >= 0 && j < cols)
                ans.push_back({i, j});

            i += dirn_i;
            j += dirn_j;

            moves -= 1;
            if (moves == 0)
            {
                int temp = dirn_i;
                dirn_i = dirn_j;
                dirn_j = -temp; // reverse dirn
                twice -= 1;
                if (twice == 0)
                {
                    twice = 2;
                    moves = next_moves;
                    next_moves += 1;
                }
                else
                    moves = next_moves - 1;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}