#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check(vector<int> base, vector<int> newBox)
    {
        if (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
            return true;
        return false;
    }
    int solveTab(int n, vector<vector<int>> &a)
    {
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {

                // include
                int take = 0;
                if (prev == -1 || check(a[curr], a[prev]))
                    take = a[curr][2] + nextRow[curr + 1];

                // exclude
                int notTake = nextRow[prev + 1];
                currRow[prev + 1] = max(take, notTake);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

public:
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (int i = 0; i < cuboids.size(); i++)
            sort(cuboids[i].begin(), cuboids[i].end());

        // sort all cuboids
        sort(cuboids.begin(), cuboids.end());

        // Use LIS
        int ans = solveTab(cuboids.size(), cuboids);

        return ans;
    }
};

int main()
{

    return 0;
}