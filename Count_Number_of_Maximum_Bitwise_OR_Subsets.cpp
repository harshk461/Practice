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
private:
    int maxi = 0;
    int count = 0;

    void solve(int i, int curr_or, vector<int> &nums)
    {
        if (i == nums.size())
        {
            if (curr_or > maxi)
            {
                maxi = curr_or;
                // start count from 1 with max_or
                count = 1;
            }
            else if (curr_or == maxi)
                count++;

            return;
        }

        // not take
        solve(i + 1, curr_or, nums);

        // take
        solve(i + 1, curr_or | nums[i], nums);
    }

public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        // int n = nums.size();
        // int max_or = 0, count = 0;

        // for (int mask = 0; mask < (1 << n); mask++)
        // {
        //     int curr_or = 0;
        //     for (int i = 0; i < n; i++)
        //     {
        //         if (mask & (1 << i))
        //         {
        //             curr_or |= nums[i];
        //         }
        //     }
        //     max_or = max(max_or, curr_or);
        // }

        // for (int mask = 0; mask < (1 << n); mask++)
        // {
        //     int curr_or = 0;
        //     for (int i = 0; i < n; i++)
        //     {
        //         if (mask & (1 << i))
        //         {
        //             curr_or |= nums[i];
        //         }
        //     }
        //     if (curr_or == max_or)
        //     {
        //         count++;
        //     }
        // }

        solve(0, 0, nums);
        return count;
    }
};

int main()
{

    return 0;
}