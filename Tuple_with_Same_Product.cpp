#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();

        unordered_map<int, int> freq;
        for (auto it : nums)
            freq[it]++;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (i != j && i != k && j != k)
                    {
                        int temp = nums[i] * nums[j];
                        if (temp % nums[k] == 0)
                            ans += (freq[i] * freq[j] * freq[k] * freq[temp / nums[k]]);
                    }
                }
            }

        }

        return ans;
    }
};

int main()
{

    return 0;
}