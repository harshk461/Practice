#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (auto i : nums)
            map[i]++;

        int ans;
        for (auto j : map)
        {
            if (j.second < 3)
            {
                return j.first;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}