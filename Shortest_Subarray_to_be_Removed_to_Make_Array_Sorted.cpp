#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n = arr.size();
        int left = 0, right = n - 1;

        // Find the longest non-decreasing prefix
        while (left + 1 < n && arr[left] <= arr[left + 1])
            ++left;

        // If the entire array is sorted
        if (left == n - 1)
            return 0;

        // Find the longest non-decreasing suffix
        while (right > 0 && arr[right - 1] <= arr[right])
            --right;

        // Initial assumption: remove everything between the prefix and suffix
        int minLength = min(n - left - 1, right);

        // Use binary search to merge prefix and suffix
        for (int i = 0; i <= left; ++i)
        {
            int j = lower_bound(arr.begin() + right, arr.end(), arr[i]) - arr.begin();
            minLength = min(minLength, j - i - 1);
        }

        return minLength;
    }
};

int main()
{

    return 0;
}
