#include <iostream>
using namespace std;

class Solution
{
private:
    void solve(int i, vector<int> &nums, unordered_map<int, int> &map, int &result, int k)
    {
        if (i == nums.size())
        {
            result++;
            return;
        }

        // not take
        solve(i + 1, nums, map, result, k);

        // take
        if (!map[nums[i] - k] && !map[nums[i] + k])
        {
            map[nums[i]]++;
            solve(i + 1, nums, map, result, k);
            map[nums[i]]--;
        }
    }

public:
    int beautifulSubsets(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int result = 0;
        unordered_map<int, int> map;
        solve(0, nums, map, result, k);

        return result;
    }
};

int main()
{

    return 0;
}