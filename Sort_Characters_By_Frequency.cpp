#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> mp;

        for (auto it : s)
        {
            mp[it]++;
        }

        vector<pair<char, int>> vec(mp.begin(), mp.end());

        sort(vec.begin(), vec.end(), [&](const auto &a, const auto &b)
             {
        if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return a.second > b.second;
        } });

        string ans = "";
        for (auto it : vec)
        {
            while (it.second)
            {
                ans += it.first;
                it.second--;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.frequencySort("Aabb");
    return 0;
}