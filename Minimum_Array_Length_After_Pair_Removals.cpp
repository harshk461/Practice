#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> map;
        for (auto it : nums)
            map[it]++;

        int maxi = 0;
        for (auto it : map)
            maxi = max(maxi, it.second);

        if (maxi <= n / 2)
        {
            if (n % 2)
                return 1;
            else
                return 0;
        }

        return 2 * maxi - n;
    }

public:
    int minLengthAfterRemovals(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 2)
        {
            if (nums[0] > nums[1])
                return 1;
            return 0;
        }

        vector<int> vis(n, 0);
        int k = 0;
        int i = 0, j = 1;

        while (i != j && i < n && j < n)
        {
            if (nums[i] < nums[j])
            {
                vis[i] = -1;
                vis[j] = -1;
                i = j + 1;
                j = i + 1;
            }
            else if (nums[i] == nums[j] && j + 1 < n)
                j++;
        }
        for (int i = 0; i < n; i++)
            if (vis[i] == -1)
                k++;

        return k;
    }
};

int main()
{

    return 0;
}