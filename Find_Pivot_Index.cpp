#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left(n - 1);
        vector<int> right(n - 1);
        int prefix = 0, suffix = 0;
        for (int i = 0; i < n; i++)
        {
            prefix += nums[i];
            left[i] = prefix;
        }
        for (int j = n - 1; j >= 0; j--)
        {
            suffix += nums[j];
            right[j] = suffix;
        }

        for (int i = 0; i < n; i++)
        {
            if (left[i] == right[i])
                return i;
        }
        return -1;
    }
};

int pivotIndex(vector<int> &arr)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int prefix = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (prefix == sum - prefix - arr[i])
            return i;
        prefix+=nums[i];
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 3};
    Solution s;
    cout << s.pivotIndex(arr);
    return 0;
}