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
    int maxHeight(int height[], int width[], int length[], int n)
    {
        vector<vector<int>> box;
        for (int i = 0; i < n; i++)
            box.push_back({length[i], width[i], height[i]});

        for (int i = 0; i < box.size(); i++)
            sort(box[i].begin(), box[i].end());

        sort(box.begin(), box.end());
        return solveTab(box.size(), box);
    }
};

int main()
{

    return 0;
}