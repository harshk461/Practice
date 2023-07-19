#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int ans = 0;
        unordered_set<int> seen(nums.begin(), nums.end());
        for (int num : nums)
        {
            if (seen.count(num - 1))
                continue;
            int len = 1;
            while (seen.count(++num))
                len++;
            ans = max(ans, len);
        }
        return ans;
    }
};

int main()
{

    return 0;
}