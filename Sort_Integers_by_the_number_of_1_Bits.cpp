#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int countBits(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            if (n % 2 == 1)
                ans++;
            n /= 2;
        }
        return ans;
    }

public:
    vector<int> sortByBits(vector<int> &arr)
    {
        vector<int> ans;
        int n = arr.size();
        vector<vector<int>> map(500);
        int maxi = 0;
        for (auto it : arr)
        {
            int bits = countBits(it);
            maxi = max(maxi, bits);
            map[bits].push_back(it);
        }

        for (int i = 0; i <= maxi; i++)
        {
            sort(map[i].begin(), map[i].end());
            for (auto j : map[i])
                ans.push_back(j);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    s.sortByBits(arr);
    return 0;
}