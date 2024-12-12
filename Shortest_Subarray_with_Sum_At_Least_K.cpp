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

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int res = INT_MAX;
        long long curSum = 0;
        deque<pair<long long, int>> q; // (prefix_sum, end_idx)

        for (int r = 0; r < nums.size(); r++)
        {
            curSum += nums[r];

            if (curSum >= k)
            {
                res = min(res, r + 1);
            }

            // Find the minimum valid window ending at r
            while (!q.empty() && curSum - q.front().first >= k)
            {
                auto [prefix, endIdx] = q.front();
                q.pop_front();
                res = min(res, r - endIdx);
            }

            // Validate the monotonic deque
            while (!q.empty() && q.back().first > curSum)
            {
                q.pop_back();
            }
            q.push_back({curSum, r});
        }

        return res == INT_MAX ? -1 : res;
    }
};

int main()
{

    return 0;
}