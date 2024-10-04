#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> ans;
    void createSubarrays(int i, vector<int> &arr, vector<int> &output)
    {
        if (i >= arr.size())
        {
            ans.push_back(output);
            return;
        }

        // take
        output.push_back(arr[i]);
        solve(i + 1, arr, output);
        output.pop_back();

        // not take
        solve(i + 1, arr, output);
    }

public:
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> temp;
        for (auto it : ans)
        {
            int sum = accumulate(it.begin(), it.end(), 0);
            temp.push_back(sum);
        }
        temp.push_back(0);
        return temp;
    }
};

int main()
{
    Solution s;
    vector<int> ar = {2, 3};
    s.subsetSums(ar, 2);
    return 0;
}