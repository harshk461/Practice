#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    for (int i = 0; i < intervals.size() - 1; i++)
    {
        cout << intervals[i + 1][0] << " " << intervals[i][1] << endl;
        cout << intervals[i][1] << " " << intervals[i + 1][0] << endl;
        if (intervals[i + 1][0] < intervals[i][1] && intervals[i + 1][0] > intervals[i][0])
        {
            vector<int> temp(2);
            temp[0] = intervals[i][0], temp[1] = intervals[i + 1][1];
            ans.push_back(temp);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    merge(arr);
    return 0;
}