#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    int longestSub(vector<int> &arr)
    {
        int maxi = 0, count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i + 1] < arr[i])
            {
                count = 0;
            }
            else
            {
                count++;
                if (count > maxi)
                    maxi = count;
            }
        }
        return maxi + 1;
    }
    int maxNonDecreasingLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int maxi = 0;
        int curr = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums1[i] >= nums1[i - 1] || nums2[i] >= nums1[i - 1])
            {
                curr++;
            }
            else
            {
                maxi = max(maxi, curr);
                curr = 1;
            }
        }
        maxi = max(maxi, curr);
        return maxi;
    }
};

int main()
{
    Solution s;
    vector<int> a1 = {4, 2};
    vector<int> a2 = {10, 4};
    cout << s.maxNonDecreasingLength(a1, a2);
    return 0;
}