#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (auto i : nums)
            map[i]++;
        int maxAns = INT_MIN;
        int ans = 0;
        for (auto i : map)
        {
            if (i.second > maxAns)
            {
                maxAns = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}