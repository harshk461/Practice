// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// private:
//     bool solve(int i, int j, int mid, vector<vector<int>> &heights, vector<vector<bool>> &vis)
//     {
//         int n = heights.size();
//         int m = heights[0].size();
//         if (i == n - 1 && j == m - 1)
//             return true;

//         vis[i][j] = true;

//         bool ans = false;

//         if (i > 0 && v[i - 1][j] == 0 && abs(heights[i][j] - heights[i - 1][j]) <= mid)
//             ans = ans || solve(i - 1, j, mid, heights, vis);
//         if (j > 0 && v[i][j - 1] == 0 && abs(heights[i][j] - heights[i][j - 1]) <= mid)
//             ans = ans || solve(i, j - 1, mid, heights, vis);
//         if (i < n - 1 && v[i + 1][j] == 0 && abs(heights[i][j] - heights[i + 1][j]) <= mid)
//             ans = ans || solve(i + 1, j, mid, heights, vis);
//         if (j < m - 1 && v[i][j + 1] == 0 && abs(heights[i][j] - heights[i][j + 1]) <= mid)
//             ans = ans || solve(i, j + 1, mid, heights, vis);

//         return ans;
//     }

// public:
//     int minimumEffortPath(vector<vector<int>> &heights)
//     {
//         int n = heights.size();
//         int m = heights[0].size();
//         int start = 0, end = 1e9;
//         int ans = INT_MAX;
//         while (start <= end)
//         {
//             vector<vector<bool>> vis(101, vector<bool>(101, false));
//             int mid = start + (end - start) / 2;
//             if (solve(0, 0, mid, heights, vis))
//             {
//                 ans = min(ans, mid);
//                 end = mid - 1;
//             }
//             else
//                 left = mid + 1;
//         }
//         return ans;
//     }
// };

// int main()
// {

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
private:
    vector<pair<int, int>> dirn = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        //{efforts,i,j}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});

        vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));
        efforts[0][0] = 0;

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int eff = top[0];
            int i = top[1];
            int j = top[2];

            if (i == n - 1 && j == m - 1)
                return eff;

            for (auto it : dirn)
            {
                int x = i + it.first;
                int y = j + it.second;

                if (x >= 0 && y >= 0 && x < n && y < m)
                {
                    int new_efforts = max(eff, abs(heights[i][j] - heights[x][y]));

                    if (new_efforts < efforts[x][y])
                    {
                        efforts[x][y] = new_efforts;
                        pq.push({new_efforts, x, y});
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{

    return 0;
}