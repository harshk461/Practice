#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        long long ans = -1;
        int n=nums.size();
        vector<int> prefix(n, 0);
        int n = 0;
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++)
            prefix[i] = nums[i] + prefix[i - 1];

        for (int i = 1; i < n; i++)
            if (prefix[i - 1] < nums[i])
                ans = prefix[i];

        return ans;
    }
};

int main()
{

    return 0;
}