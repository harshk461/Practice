#include <bits/stdc++.h>
using namespace std;

int findCircleNum(vector<vector<int>> &isConnected)
{
    unordered_map<int, int> map;
    int ans = isConnected.size();
    for (int i = 0; i < isConnected.size(); i++)
    {
        map[i + 1] = isConnected[0][i];
    }
    for (int i = 1; i < isConnected.size(); i++)
    {
        vector<int> temp = isConnected[i];
        for (int j = 0; j < isConnected.size(); j++)
        {
            if (temp[j] == 1 || map[j + 1] == 1)
            {
                ans--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << findCircleNum(arr);
    return 0;
}