#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));
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

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int nbr_sum = img[i][j];
                int nbr_count = 0;

                for (auto it : dirn)
                {
                    int x = i + it[0];
                    int y = j + it[1];

                    if (x < m && x >= 0 && y < n && y >= 0)
                    {
                        nbr_count++;
                        nbr_sum += img[x][y];
                    }
                }

                nbr_count++;
                ans[i][j] = (nbr_sum) / (nbr_count);
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> arr = {{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};
    Solution s;
    vector<vector<int>> ans = s.imageSmoother(arr);

    for (auto it : ans)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}