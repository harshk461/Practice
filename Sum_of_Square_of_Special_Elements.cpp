#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumOfSquares(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
                ans += pow(nums[i - 1], 2);
        }
        return ans;
    }
};

int main()
{

    return 0;
}