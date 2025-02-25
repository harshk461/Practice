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
    int waysToSplitArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];

        int count = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (prefix[i] > (prefix[n - 1] - prefix[i - 1]))
                count++;
        }
        return count;
    }
};

int main()
{

    return 0;
}