#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> map({0, 1});
        int ans = 0;
        int prefix = 0;

        for (auto num : nums)
        {
            prefix += num;
            int target = prefix - k;
            if (auto it = map.find(target); it != map.cend())
                ans += it.second;
            map[prefix]++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}