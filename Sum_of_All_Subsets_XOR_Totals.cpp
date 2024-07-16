#include <iostream>
using namespace std;

class Solution
{
private:
    int solve(int i, int curr, vector<int> &nums)
    {
        if (i == nums.size())
            return curr;

        int take = solve(i + 1, curr ^ nums[i], nums);
        int notTake = solve(i + 1, curr, nums);

        return take + notTake;
    }

public:
    int subsetXORSum(vector<int> &nums)
    {
        return solve(0, 0, nums);
    }
};

int main()
{

    return 0;
}