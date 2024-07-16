#include <iostream>
using namespace std;

class Solution
{
private:
    int calculateRowScore(vector<int> &arr)
    {
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] == 1)
                ans += (pow(2, arr.size() - i - 1));

        return ans;
    }

public:
    int matrixScore(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // row transformation

        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 0)
            {
                for (int j = 0; j < n; j++)
                    grid[i][j] = !grid[i][j];
            }
        }

        // column transformation

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < m; j++)
                if (grid[j][i] == 0)
                    count++;

            if (count > row - count)
                for (int j = 0; j < m; j++)
                    grid[j][i] = !grid[j][i];
        }

        // for (auto it : grid)
        // {
        //     for (auto i : it)
        //         cout << i << " ";
        //     cout << endl;
        // }

        // calculating score
        int ans = 0;
        for (auto it : grid)
            ans += calculateRowScore(it);

        return ans;
    }
};

int main()
{

    return 0;
}