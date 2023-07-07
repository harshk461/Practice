#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int ans = nums[0];
        int dpMax = nums[0];
        int dpMin = nums[0];

        for (int i = 1; i < n; i++)
        {
            int num = nums[i];
            int prevMin = dpMin;
            int prevMax = dpMax;
            if (num < 0)
            {
                dpMin = min(prevMax * num, num);
                dpMax = max(prevMin * num, num);
            }
            else
            {
                dpMin = min(prevMin * num, num);
                dpMax = max(prevMax * num, num);
            }
            ans = max(ans, dpMax);
        }
        return ans;
    }
};

int main()
{

    return 0;
}