#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (i == n - 1 && j == n - 1)
            if (grid[i][j])
                return 1;
            else
                return 0;

        int count=0;
        //down
        count=solve(i+1,j,grid);
        //right
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        return solve(0, 0, grid);
    }
};

int main()
{

    return 0;
}