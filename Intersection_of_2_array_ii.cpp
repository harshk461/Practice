#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    unordered_map<int, int> map;

    if (nums1.size() > nums2.size())
    {
        swap(nums1, nums2);
    }

    for (auto i : nums1)
    {
        map[i]++;
    }

    for (auto i : nums2)
    {
        if (map[i] > 0)
        {
            ans.push_back(i);
            map[i]--;
        }
    }

    return ans;
}

int main()
{

    return 0;
}