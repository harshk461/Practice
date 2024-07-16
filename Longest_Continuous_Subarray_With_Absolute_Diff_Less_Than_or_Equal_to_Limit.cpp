#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = nums.size();

        int i = 0, j = 0;
        int ans = 0;
        int prev = -1;

        multiset<int> ms;

        while (j < n)
        {
            if (prev != j)
            {
                prev = j;
                ms.insert(nums[j]);
            }
            int mini = *ms.begin(), maxi = *(--ms.end());

            if (abs(mini - nums[j]) <= limit && abs(maxi - nums[j]) <= limit)
            {
                ans = max(ans, j - i + 1);
                j++;
            }
            else
            {
                auto it = ms.find(nums[i]);
                ms.erase(it);
                i++;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}