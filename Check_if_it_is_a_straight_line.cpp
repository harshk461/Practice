#include <bits/stdc++.h>
using namespace std;

bool checkStraightLine(vector<vector<int>> &coordinates)
{
    int x1 = coordinates[0][0], x2 = coordinates[1][0];
    int y1 = coordinates[0][1], y2 = coordinates[1][1];
    int dx = x2 - x1;
    int dy = y2 - y1;
    for (int i = 2; i < coordinates.size(); i++)
    {
        int x = coordinates[i][0];
        int y = coordinates[i][1];
        if ((x - x1) * dy != dx * (y - y1))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 6},
        {6, 7},
    };
    cout << checkStraightLine(arr);
    return 0;
}