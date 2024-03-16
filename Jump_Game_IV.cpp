#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    unordered_map<int, vector<int>> map;

    int solve(int index, vector<int> &arr, vector<int> &vis)
    {
        if (index < 0 || index >= arr.size())
            return 1e5;

        if (vis[index] == 1)
            return 1e5;

        if (index == arr.size() - 1)
            return 0;

        int steps = 1e5;
        vis[index] = 1;

        steps = min(steps, 1 + solve(index + 1, arr, vis));
        steps = min(steps, 1 + solve(index - 1, arr, vis));

        for (int i = 0; i < map[arr[index]].size(); i++)
            if (map[arr[index]][i] != index)
                steps = min(steps, 1 + solve(map[arr[index]][i], arr, vis));

        vis[index] = 0;
        return steps;
    }

public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
            map[arr[i]].push_back(i);

        return solve(0, arr, vis);
    }
};

int main()
{
    Solution s;
    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    cout << s.minJumps(arr);
    return 0;
}