#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int maxCount = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int d = nums[i + 1] - nums[i];
            int count = 1;
            while (i + 1 < nums.size() && nums[i + 1] - nums[i] == d)
            {
                i++;
                count++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};

int main()
{

    return 0;
}