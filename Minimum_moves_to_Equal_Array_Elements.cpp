#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 0; i--)
            count += nums[i] - nums[0];
        return count;
    }
};

int main()
{

    return 0;
}