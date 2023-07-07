#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        bool flag = false;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                if (flag)
                    return false;
                if (i == 1 || nums[i] >= nums[i - 2])
                    nums[i - 1] = nums[i]; // Decrease previous value
                else
                    nums[i] = nums[i - 1]; // Increase current value

                flag = true;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}