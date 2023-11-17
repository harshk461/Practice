#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int temp = nums[i] + nums[j];
            ans = max(ans, temp);
            i++, j--;
        }
        return ans;
    }
};

int main()
{

    return 0;
}