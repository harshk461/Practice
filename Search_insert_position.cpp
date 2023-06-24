#include <bits/stdc++.h>
using namespace std;

// linear search approach
// int searchInsert(vector<int> &nums, int target)
// {
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] >= target)
//         {
//             return i;
//         }
//     }
//     return nums.size();
// }

// binary search approach O(logn)
int binarysearch(vector<int> &arr, int target)
{
    int ans = -1;
    int left = 0, right = arr.size() - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] > target)
        {
            right = mid - 1;
            ans = mid;
        }
        else
        {
            left = mid + 1;
            ans = mid + 1;
        }
    }
    return ans;
}

int searchInsert(vector<int> &nums, int target)
{
    return binarysearch(nums, target);
}

int main()
{
    vector<int> arr = {1, 3, 5, 6};
    cout << searchInsert(arr, 7);
    return 0;
}