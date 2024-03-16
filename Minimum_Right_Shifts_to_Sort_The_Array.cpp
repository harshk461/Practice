#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &nums)
    {
        int min = -1;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i - 1] > nums[i])
            {
                min = i;
                count++;
            }
        }

        if (min == -1)
            return 0;
        if (count > 1 || nums[0] < nums[nums.size() - 1])
            return -1;

        return nums.size() - min;
    }

public:
    int minimumRightShifts(vector<int> &nums)
    {
        if (nums.size() == 2)
        {
            if (nums[0] > nums[1])
                return 1;
            else
                return 0;
        }
        int mini = *min_element(nums.begin(), nums.end());
        int i;
        for (i = 0; i < nums.size(); i++)
            if (mini == nums[i])
                break;

        if (i == 0)
            return 0;

        if (i == nums.size() - 1)
            return nums.size() - 1;

        if (nums[i - 1] > nums[i + 1])
            return (nums.size() - i - 1);

        // return -1;
        return solve(nums);
    }
};

class Solution
{
public:
    int minimumRightShifts(vector<int> &nums)
    {
        int min = -1, count = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                min = i;
                count++;
            }
        }

        if (min == -1)
            return 0;
        if (count > 1 || nums[0] < nums[n - 1])
            return -1;
        return n - min;
    }
};

int main()
{

    return 0;
}