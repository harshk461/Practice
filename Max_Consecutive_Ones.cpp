#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ans = 0;
        int sum = 0;
        for (auto num : nums)
        {
            if (num == 1)
                ans = max(ans, sum++);
            else
                sum = 0;
        }
        return ans;
    }
};

int main()
{

    return 0;
}