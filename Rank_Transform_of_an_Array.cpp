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
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> nums = arr;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> map;

        int rank = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (map.find(nums[i]) != map.end())
                map[nums[i]] = min(map[nums[i]], rank);
            else
                map[nums[i]] = rank++;
        }

        for (auto it : map)
            cout << it.first << " " << it.second << endl;
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = map[arr[i]];
        }
        return arr;
    }
};

int main()
{

    return 0;
}