#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        vector<int> count;
        for (auto it : arr)
        {
            int sum = accumulate(it.begin(), it.end(), 0);
            // cout << sum << " ";
            count.push_back(sum);
        }

        int ans = -1;
        int maxi = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            if (count[i] > 0 && count[i] > maxi)
            {
                // cout << i << " ";
                maxi = count[i];
                ans = i;
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> arr = {{0, 0, 1, 1}, {0, 0, 0, 1}};
    Solution s;
    s.rowWithMax1s(arr);
    return 0;
}