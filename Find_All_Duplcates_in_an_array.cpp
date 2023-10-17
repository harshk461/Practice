#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (auto num : nums)
            map[num]++;
        vector<int> ans;
        for (auto it : map)
            if (it.second >= 2)
                ans.push_back(it.first);
        return ans;
    }
};

int main()
{

    return 0;
}