#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> ans(2);

    set<int> s1(nums1.begin(), nums1.end());
    set<int> s2(nums2.begin(), nums2.end());

    for (auto i : s1)
    {
        if (!s2.count(i))
        {
            ans[0].push_back(i);
        }
    }

    for (auto i : s2)
    {
        if (!s1.count(i))
        {
            ans[1].push_back(i);
        }
    }

    return ans;
}
int main()
{
    vector<int> s1 = {1, 2, 3};
    vector<int> s2 = {2, 4, 6};
    findDifference(s1, s2);
    return 0;
}