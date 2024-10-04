#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    set<vector<int>> ans;
    void create(int index, vector<int> &arr, vector<int> output)
    {
        if (index >= arr.size())
        {
            ans.insert(output);
            return;
        }

        // take
        output.push_back(arr[index]);
        solve(index + 1, arr, output);
        output.pop_back();

        // not take
        solve(index + 1, arr, output);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> output;
        sort(nums.begin(), nums.end());
        create(0, nums, out_of_range);

        vector<vector<int>> res(ans.begin(), ans.end());

        return res;
    }
};

int main()
{

    return 0;
}