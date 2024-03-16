#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        for (auto it : arr)
            mp[it]++;

        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [&](const pair<int, int> &a, const pair<int, int> &b)
             { return a.second < b.second; });

        set<int> ans;
        for (auto it : v)
        {
            if (it.second <= k)
                k -= it.second;
            else
                ans.insert(it.first);
        }
        return ans.size();
    }
};

int main()
{
    Solution s;
    vector<int> arr = {4, 3, 1, 1, 3, 3, 2};
    s.findLeastNumOfUniqueInts(arr, 3);
    return 0;
}