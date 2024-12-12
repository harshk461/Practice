#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
private:
    bool isPossible(int max_balls_in_bag, vector<int> &nums, int max_operations)
    {
        int total = 0;
        for (auto num : nums)
        {
            int op = ceil(num / (double)max_balls_in_bag) - 1;
            total += op;

            if (total > max_operations)
                return false;
        }

        return true;
    }

public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (isPossible(mid, nums, maxOperations))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};

int main()
{

    return 0;
}