#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        vector<vector<int>> ans;
        vector<int> map[groupSizes.size() + 1];
        for (int i = 0; i < groupSizes.size(); i++)
        {
            map[groupSizes[i]].push_back(i);

            if (map[groupSizes[i]].size() == groupSizes[i])
            {
                ans[i].push_back(map[groupSizes[i]]);
                map[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}