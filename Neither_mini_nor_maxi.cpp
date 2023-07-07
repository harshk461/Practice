#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findNonMinOrMax(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return -1;

        sort(nums.begin(), nums.end());
        int mid = nums.size() / 2;
        return nums[mid];
    }
};

int main()
{

    return 0;
}