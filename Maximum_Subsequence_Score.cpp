#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums2[i] < nums2[j])
                {
                    swap(nums2[i], nums2[j]);
                    swap(nums1[i], nums1[j]);
                }
            }
        }
        int mini = nums2[k - 1];
        int sum = 0;
        for (int i = n - 1; i >= n - k; i--)
            sum += nums1[i];
        return mini * sum;
    }
};

int main()
{
    vector<int> arr1 = {4, 2, 3, 1, 1};
    vector<int> arr2 = {7, 5, 10, 9, 6};
    Solution s;
    s.maxScore(arr1, arr2, 3);
    return 0;
}