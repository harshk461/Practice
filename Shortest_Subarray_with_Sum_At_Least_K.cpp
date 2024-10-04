#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(int k, int mid, vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.begin() + mid, 0);
        // cout<<sum<<" ";
        if (sum >= k)
            return true;
        int j = 0;
        for (int i = mid; i < nums.size(); i++)
        {
            // cout<<sum<<" ";
            sum -= nums[j++];
            sum += nums[i];
            if (sum >= k)
                return true;
        }
        // cout<<endl;

        return false;
    }

    int shortestSubarray(vector<int> &nums, int k)
    {

        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            if (nums[i] >= k)
                return 1;
        int low = 1;
        int high = n;
        int mid = (high + low) / 2;
        while (low < high)
        {
            if (check(k, mid, nums))
            {
                ans = mid;
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
            mid = (high + low) / 2;
        }

        // return ans==INT_MAX?-1:ans;
        return mid;
    }
};

int main()
{

    return 0;
}