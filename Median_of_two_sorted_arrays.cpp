#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// private:
//     vector<int> merge(vector<int> &nums1, vector<int> &nums2)
//     {
//         int i = 0, j = 0;
//         vector<int> ans;
//         while (i < nums1.size() && j < nums2.size())
//         {
//             if (nums1[i] < nums2[j])
//                 ans.push_back(nums1[i++]);
//             else if (nums1[i] > nums2[j])
//                 ans.push_back(nums2[j++]);
//         }

//         while (i < nums1.size())
//         {
//             ans.push_back(nums1[i++]);
//         }

//         while (j < nums2.size())
//         {
//             ans.push_back(nums2[j++]);
//         }
//         return ans;
//     }

// public:
//     double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
//     {
//         vector<int> merged = merge(nums1, nums2);
//         double ans;
//         if (merged.size() % 2 == 0)
//         {

//             ans = ((double)merged[merged.size() / 2] + (double)merged[(merged.size() - 1) / 2]) / 2;
//         }
//         else
//         {
//             ans = merged[merged.size() / 2];
//         }
//         return ans;
//     }
// };

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int i = 0, j = 0;
    int count;
    int n = nums1.size(), m = nums2.size();
    int m1 = -1, m2 = -1;
    for (count = 0; count <= (m + n) / 2; count++)
    {
        m2 = m1;
        if (i != n && j != m)
        {
            m1 = nums[i] > nums2[j] ? nums2[j++] : nums1[i++];
        }
        else if (i < n)
        {
            m1 = nums1[i++];
        }
        else
        {
            m1 = nums2[j++];
        }
    }

    if ((m + n) % 2 == 1)
        return m1;
    else
        return (m1 + m2) / 2;
}

int main()
{

    return 0;
}