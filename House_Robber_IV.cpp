#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int test(vector<int> &nums, int capacity)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] <= capacity)
                ans++, ++i;

        return ans;
    }

public:
    int minCapability(vector<int> &nums, int k)
    {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());

        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (test(nums, m) >= k)
                r = m;
            else
                l = m + 1;
        }
        return l
    }
};

int main()
{

    return 0;
}