#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int i = 0; i < n - k; i++)
        {
            if (nums[i] > nums[i + k])
                return false;
        }
        return true;
    }
};

int main()
{
    vector<int> arr = { 2,
                        2,
                        3,
                        1,
                        1,
                        0 } return 0;
}