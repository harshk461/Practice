#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int ans;
    int n = nums.size();
    vector<int> temp;
    for (int i = 0; i <= n; i++)
        temp.push_back(0);

    for (int i = 0; i < n; i++)
    {
        temp[nums[i] - 1] = 1;
    }

    for (int i = 0; i <= n; i++)
    {
        if (temp[i] == 0)
        {
            ans = i + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 0, 1};
    missingNumber(arr);
    return 0;
}