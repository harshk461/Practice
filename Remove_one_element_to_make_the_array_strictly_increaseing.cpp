#include <bits/stdc++.h>
using namespace std;
bool canBeIncreasing(vector<int> &nums)
{
    bool removed = false;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] >= nums[i])
        {
            if (removed)
            {
                return false;
            }
            removed = true; // remove nums[i-1];
            if (i > 1 && nums[i - 2] >= nums[i])
                nums[i] = nums[i - 1];
        }
    }
    return true;
}

int main()
{
    vector<int> arr = {1, 2, 10, 5, 7};
    cout << isSorted(arr, arr.size(), 3);
    return 0;
}