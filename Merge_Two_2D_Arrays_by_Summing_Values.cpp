#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        map<int, int> count;
        for (auto it : nums1)
            count[it[0]] = it[1];

        for (auto it : nums2)
        {
            if (count.find(it[0]) == count.end())
                count[it[0]] = it[1];
            else
                count[it[0]] += it[1];
        }

        vector<vector<int>> ans;
        for (auto it : count)
            ans.push_back({it.first, it.second});

        return ans;
    }
};

int main()
{

    return 0;
}