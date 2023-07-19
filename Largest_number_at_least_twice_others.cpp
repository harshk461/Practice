#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int maxIndex = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (i != j && nums[i] != nums[j] && nums[i] >= 2 * nums[j])
                {
                    count++;
                }
            }
            if (count == nums.size() - 1)
                maxIndex = i;
        }
        return maxIndex;
    }
};

int main()
{

    return 0;
}