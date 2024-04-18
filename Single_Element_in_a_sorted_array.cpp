#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int brute(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int mid = i + (j - i) / 2;

        unordered_map<int, int> map;
        for (auto it : nums)
            map[it]++;

        for (auto it : map)
            if (it.second == 1)
                return it.first;
        return -1;
    }

    int solve(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] != nums[mid + 1])
                end = mid + 1;
            else
                start = mid + 2;
        }

        return nums[start];
    }

public:
    int singleNonDuplicate(vector<int> &nums)
    {
        return solve(nums);
    }
};

int main()
{

    return 0;
}