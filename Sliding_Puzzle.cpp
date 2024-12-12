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
    vector<vector<int>> dirn = {
        {1, 3},
        {0, 2, 4},
        {1, 5},
        {0, 4},
        {3, 5, 1},
        {4, 2},
    };

    void dfs(string st, unordered_map<string, int> &vis, int zero_pos, int moves)
    {
        if (vis.count(st) && vis[st] <= moves)
            return;

        vis[st] = moves;

        for (auto next : dirn[zero_pos])
        {
            swap(st[zero_pos], st[next]);
            dfs(st, vis, next, moves + 1);
            swap(st[zero_pos], st[next]);
        }
    }

public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        string st;
        for (auto it : board)
        {
            for (auto i : it)
                st += to_string(i);
        }

        unordered_map<string, int> vis;
        dfs(st, vis, st.find('0'), 0);

        return vis.count("123450") ? vis["123450"] : -1;
    }
};

int main()
{

    return 0;
}