#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, string output, vector<vector<char>> &mat,
           vector<string> &ans, vector<vector<int>> dirn)
{
    if (output.size() == 3)
    {
        ans.push_back(output);
        output = "";
        return;
    }

    for (auto it : dirn)
    {
        int x = i + it[0];
        int y = i + it[1];
        if (x >= 0 && x < 3 && y >= 0 && y < 3)
        {
            output.push_back(mat[x][y]);
            solve(x, y, output, mat, ans, dirn);
            output.pop_back();
        }
    }
}

int main()
{
    string s1, s2, s3;
    vector<vector<char>> mat(3);
    mat[0] = {s1[0], s1[1], s1[2]};
    mat[1] = {s2[0], s2[1], s2[2]};
    mat[2] = {s3[0], s3[1], s3[2]};

    vector<vector<int>> dirn = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1},
    };

    vector<string> ans;
    string output = "";
    solve(0, 0, output, mat, ans, dirn);

    for (auto it : ans)
        cout << it << " ";
    return 0;
}