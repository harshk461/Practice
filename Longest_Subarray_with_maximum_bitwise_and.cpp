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
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size(), maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > maxi)
                maxi = nums[i];
        }
        int l = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            while (i < n && nums[i] == maxi)
            {
                temp++;
                i++;
            }
            l = max(temp, l);
        }
        return l;
    }
};

int main()
{

    return 0;
}