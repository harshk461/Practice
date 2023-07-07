#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {
        int count = 0;
        int l = -1, r = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > right)
                l = i;
            if (nums[i] >= left)
                r = i;

            count += (r - l);
        }
        return count;
    }
};

int main()
{

    return 0;
}