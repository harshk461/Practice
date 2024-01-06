#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto it : nums)
            mp[it]++;

        int index = 0;

        // finding maximum count
        int maxi = 0;
        for (auto it : mp)
            maxi = max(maxi, it.second);

        // for (int i = 0; i < maxi; i++)
        //     ans.push_back({});

        vector<vector<int>> ans(maxi);

        for (auto it : mp)
        {
            while (it.second > 0)
            {
                if (it.second == 1)
                {
                    ans[index].push_back(it.first);
                    index = 0;
                }
                else
                    ans[index++].push_back(it.first);
                it.second--;
            }
        }

        for (auto it : ans)
        {
            for (auto i : it)
                cout << i << " ";
            cout << endl;
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    Solution s;
    s.findMatrix(arr);
    return 0;
}