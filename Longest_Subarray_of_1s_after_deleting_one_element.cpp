#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int ans = 0;
        int count = 0;
        for (int l = 0, r = 0; r < nums.size(); r++)
        {
            if (nums[r] == 0)
                count++;
            while (count == 2)
                if (nums[l++] == 0)
                    count--;
            ans = max(ans, r - l);
        }
        return ans;
    }
};

int main()
{

    return 0;
}