#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> solve(vector<int> &nums, vector<vector<int>> &queries)
    {
        int m = queries.size();
        // storing sum of all even numbers
        int sum = 0;
        for (auto it : nums)
            if (it % 2 == 0)
                sum += it;
        cout << sum << " ";
        vector<int> ans(m, 0);
        int idx = 0;
        for (auto query : queries)
        {
            int val = query[0];
            int index = query[1];

            // before doing query if our element is even we have to remove it
            // because we don't know it will be even or odd after operation sed

            if (nums[index] % 2 == 0)
            {
                sum -= nums[index];
            }

            nums[index] += val;

            if (nums[index] % 2 == 0)
            {
                sum += nums[index];
            }
            ans[idx++] = sum;
        }

        return ans;
    }

    vector<int> brute(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int m = queries.size();

        vector<int> ans(m, 0);
        int idx = 0;
        for (auto query : queries)
        {
            int val = query[0];
            int index = query[1];

            int temp = 0;
            for (int i = 0; i < n; i++)
            {
                if (i == index)
                {
                    temp += (nums[i] + val);
                    nums[i] = nums[i] + val;
                }
                else
                    temp += nums[i];
            }

            ans[idx++] = temp;
        }
    }

public:
    vector<int> sumEvenAfterQueries()
    {
        return solve(nums, queries);
    }
};

int main()
{

    return 0;
}