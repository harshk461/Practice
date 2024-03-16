#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        int row = nums.size() / 3;
        vector<vector<int>> ans(row, vector<int>(3, 0));
        sort(nums.begin(), nums.end());
        for (int i = 0; i < m; i++)
            ans[i / 3][i % 3] = nums[i];

        for (int i = 0; i < row; i++)
        {
            if ((ans[i][2] - ans[i][1]) > k)
                return {};
        }

        return ans;
    }
};

int main()
{

    return 0;
}