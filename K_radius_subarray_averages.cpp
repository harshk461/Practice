#include <bits/stdc++.h>
using namespace std;

vector<int> getAverages(vector<int> &nums, int k)
{
    int n = nums.size();
    int len = 2 * k + 1; // len of subarrayE
    vector<int> ans(n, -1);
    if (len > n)
    {
        return ans;
    }

    long sum = accumulate(nums.begin(), nums.begin() + len, 0L);

    for (int i = k; i + k < n; i++)
    {
        ans[i] = sum / len;
        if (i + k + 1 < n)
        {
            sum += nums[i + k + 1] - nums[i - k];
        }
    }
    return ans;
}

int main()
{

    return 0;
}