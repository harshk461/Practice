#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    int slow = nums[nums[0]];
    int fast = nums[nums[nums[0]]];

    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int findDuplicate(vector<int> &nums)
{
    unordered_map<int, int> map;
    for (auto i : nums)
    {
        map[i]++;
    }
    int ans = 0;
    for (auto i : map)
    {
        if (i.second > 1)
            ans = i.first;
    }
    return ans;
}

int main()
{

    return 0;
}