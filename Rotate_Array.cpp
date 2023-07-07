#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int s = nums.size() - 1, e = nums.size() - 1 - k;
        while (s > e)
        {
            swap(nums[s], nums[e]);
            s--;
            e++;
        }
        
    }
};

int main()
{

    return 0;
}