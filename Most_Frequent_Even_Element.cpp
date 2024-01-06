#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        map<int, int> map;
        for (auto it : nums)
            if (it % 2 == 0)
                map[it]++;

        int ans = -1;
        int freq = INT_MIN;

        for (auto it : map)
        {
            if (it.second > freq)
            {
                freq = it.second;
                ans = it.first;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}