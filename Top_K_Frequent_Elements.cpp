#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<pair<int, int>> map;
    vector<int> ans;
    set<int> temp(nums.begin(), nums.end());
    for (auto i : temp)
    {
        int val_count = count(nums.begin(), nums.end(), i);
        pair<int, int> val_pair = make_pair(i, val_count);
        map.push_back(val_pair);
    }
    sort(map.begin(), map.end(), [&](pair<int, int> a, pair<int, int> b)
         { return a.second > b.second; });
    int n = 0;
    for (auto i : map)
    {
        ans.push_back(i.first);
        n++;
        if (n == k)
        {
            break;
        }
    }
    return ans;
}
int main()
{
    vector<pair<int, int>> map = {make_pair(0, 0), make_pair(3, 3),
                                  make_pair(2, 2),
                                  make_pair(1, 1)};
    sort(map.begin(), map.end(), [&](pair<int, int> a, pair<int, int> b)
         { return a.second > b.second; });
    // vector<int> arr = {1, 1, 2, 3};
    // cout << count(arr.begin(), arr.end(), 1) << " ";
    for (auto i : map)
    {
        cout << i.first << " ";
    }
    return 0;
}