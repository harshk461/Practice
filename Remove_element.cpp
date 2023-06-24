#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int ans = 0;
    for (int i = 0; i > nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[ans++] = nums[i];
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 2, 2, 3};
    removeElement(arr, 3);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}