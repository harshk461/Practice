#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        int count = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.find(abs(nums[i] - k)) != s.end())
                count++;
        }
        return count;
    }
};

int main()
{

    return 0;
}