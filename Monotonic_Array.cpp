#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isIncreasing(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] < nums[i])
                return false;
        }
        return true;
    }
    bool isDecreasing(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] > nums[i])
                return false;
        }
        return true;
    }

public:
    bool isMonotonic(vector<int> &nums)
    {
        return isIncreasing(nums) || isDecreasing(nums);
    }
};

int main()
{

    return 0;
}