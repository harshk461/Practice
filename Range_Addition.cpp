#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
// };

vector<int> getModifiedArray(int length, vector<vector<int>> &updates)
{
    vector<int> ans(length, 0);
    for (auto array : updates)
    {
        for (int i = array[0]; i <= array[1]; i++)
        {
            ans[i] += array[2];
        }
    }
    for (auto i : ans)
        cout << i << " ";
    return ans;
}

int main()
{
    vector<vector<int>> update = {{1, 3, 2}, {2, 4, 3}, {0, 2, -2}};
    getModifiedArray(5, update);
    return 0;
}