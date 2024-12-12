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
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int right = 0;
        int max_beauty = 0;

        for (int left = 0; left < nums.size(); left++)
        {
            while (right < nums.size() && nums[right] - nums[left] <= 2 * k)
                right++;

            max_beauty = max(max_beauty, right - left);
        }

        return max_beauty;
    }
};

int main()
{

    return 0;
}