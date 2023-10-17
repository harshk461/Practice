#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> merge(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        vector<int> ans;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
                ans.push_back(nums1[i++]);
            else if (nums1[i] > nums2[j])
                ans.push_back(nums2[j++]);
        }

        while (i < nums1.size())
        {
            ans.push_back(nums1[i++]);
        }

        while (j < nums2.size())
        {
            ans.push_back(nums2[j++]);
        }
        return ans;
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> merged = merge(nums1, nums2);
        if (merged.size() % 2 == 0)
        {
            return merged[merged.size() / 2];
        }
        else
        {
            return (merged[merged.size() - 1 / 2] + merged[merged.size() / 2]) / 2;
        }
    }
};

int main()
{

    return 0;
}