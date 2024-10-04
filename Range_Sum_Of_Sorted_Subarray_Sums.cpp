#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void createSubarrays(vector<int> &nums, int n, vector<int> &ans)
    {
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                int sum = accumulate(nums.begin(), nums.end(), 0);
                ans.push_back(sum);
            }
        }
    }

public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        // for (auto it : subarrays)
        // {
        //     for (auto i : it)
        //         cout << i << " ";
        //     cout << endl;
        // }

        vector<int> sorted_sum;
        createSubarrays(nums, n, sorted_sum);

        sort(sorted_sum.begin(), sorted_sum.end());
        int ans = 0;
        for (int i = left - 1; i < right; i++)
            ans += sorted_sum[i];
        return ans;
    }
};

int main()
{

    vector<int> arr = {10, 20, 30, 40, 50};
    cout << *lower_bound(arr.begin(), arr.end(), 30);
    return 0;
}