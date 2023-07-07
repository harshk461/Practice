#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;
        unordered_map<int, int> s;
        int ans = 0;
        for (auto n : nums)
            s[n]++;
        for (auto i : s)
        {
            if (k == 0)
            {
                if (s[i.first] > 1)
                    ans++;
            }
            else
            {
                if (s.count(i.first - k))
                    ans++;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}