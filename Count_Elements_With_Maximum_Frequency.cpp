#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (auto it : nums)
            map[it]++;

        int maxi = 1;
        for (auto it : map)
            maxi = max(maxi, it.second);

        int ans = 0;
        for (auto it : map)
            if (it.second == maxi)
                ans += it.second;

        return ans;
    }
};

int main()
{

    return 0;
}