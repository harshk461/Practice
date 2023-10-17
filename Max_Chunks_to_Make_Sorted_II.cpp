#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        // generate a right min
        vector<int> right_min(arr.size() + 1);

        right_min[arr.size()] = INT_MAX;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            right_min[i] = min(right_min[i + 1], arr[i]);
        }

        // iterate an array and manage left max as well as count
        int left_max = INT_MIN;
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            left_max = max(left_max, arr[i]);
            if (left_max <= right_min[i + 1])
                count++;
        }
        return count;
    }
};

int main()
{
    vector<int> arr = {2, 1, 3, 4, 4};
    Solution s;
    cout << s.maxChunksToSorted(arr);
    return 0;
}