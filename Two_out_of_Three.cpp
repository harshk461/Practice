#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        unordered_map<int, set<int>> map;
        set<int> distinctElements;
        for (auto it : nums1)
            map[it].insert(1);
        for (auto it : nums2)
            map[it].insert(2);
        for (auto it : nums3)
            map[it].insert(3);

        vector<int> ans;

        for (auto it : map)
        {
            cout << it.first << " ";
            for (auto i : it.second)
                cout << i << " ";
            cout << endl;
        }

        for (auto it : map)
            if (it.second.size() >= 2)
                ans.push_back(it.first);

        return ans;
    }
};

int main()
{
    vector<int> a = {3, 1};
    vector<int> b = {2, 3};
    vector<int> c = {1, 2};
    Solution s;
    s.twoOutOfThree(a, b, c);
    return 0;
}