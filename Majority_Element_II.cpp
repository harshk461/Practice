#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int times = nums.size() / 3;
        unordered_map<int, int> map;
        vector<int> ans;
        for (auto i : nums)
        {
            map[i]++;
        }

        for (auto it : map)
        {
            if (it.second > times)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}