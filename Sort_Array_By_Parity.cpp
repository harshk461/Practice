#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int count = 0;
        vector<int> ans(nums.begin(), nums.end());
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] % 2 == 0)
            {
                swap(ans[i], ans[count]);
                count++;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    Solution s;
    vector<int> ans = s.sortArrayByParity(arr);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}