#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasTrailingZeros(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && nums[i] % 2 == 0 && nums[j] % 2 == 0)
                    return true;
        return false;
    }
};

int main()
{

    return 0;
}