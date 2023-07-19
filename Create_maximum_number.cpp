#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        if (nums1.size() < nums2.size())
        {
            swap(nums1, nums2);
        }
        vector<int> ans(k);
        int i;
        for (i = 0; i < nums1.size(); i++)
        {
            ans[i] = nums[i];
        }
        for(int j=)
    }
};

int main()
{
    vector<int> a1 = {3, 4, 6, 5};
    vector<int> a2 = {9, 1, 2, 5, 8, 3};
    Solution s;
    s.maxNumber(a1, a2, 5);
    return 0;
}