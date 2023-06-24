#include <bits/stdc++.h>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<int>> &arr, vectpr<vector<bool>> &vis, int n)
{
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) &&
        (vis[newx][newy] != 1) && (arr[newx][newy] == 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(int x, int y, vector<vector<int>> &arr, int n,
           vector<string> &ans, vector<vector<bool>> &vis, string path)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // 4 movements
    // D L R U

    // down
    if (isSafe(x + 1, y, arr, vis, n))
    {
        vis[x][y] = 1;
        solve(x + 1, y, arr, n, ans, vis, path + 'D');
        vis[x][y] = 0;
    }
    // Left
    if (isSafe(x, y - 1, arr, vis, n))
    {
        vis[x][y] = 1;
        solve(x, y - 1, arr, n, ans, vis, path + 'L');
        vis[x][y] = 0;
    }
    // Right
    if (isSafe(x, y + 1, arr, vis, n))
    {
        vis[x][y] = 1;
        solve(x, y + 1, arr, n, ans, vis, path + 'R');
        vis[x][y] = 0;
    }

    // Up
    if (isSafe(x - 1, y, arr, vis, n))
    {
        vis[x][y] = 1;
        solve(x - 1, y, arr, n, ans, vis, path + 'U');
        vis[x][y] = 0;
    }
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<bool>>
        visited(n, vector<bool>(n, 0));
    string path = "";

    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}

int main()
{

    return 0;
}