#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (auto it : nums)
            map[it]++;

        int ans = 0;
        for (auto it : map)
        {
            if (it.second == 1)
                return -1;

            ans += ceil((double)(it.second) / 3);
        }
        cout << ans;
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {14, 12, 14, 14, 12, 14, 14, 12, 12, 12, 12, 14, 14, 12, 14, 14, 14, 12, 12};
    s.minOperations(arr);
    return 0;
}