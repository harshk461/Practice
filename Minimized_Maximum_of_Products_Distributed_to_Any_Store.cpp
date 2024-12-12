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
private:
    bool isPossible(int n, vector<int> &arr, int mid)
    {
        int store = 0;
        for (auto it : arr)
        {
            store += (it / mid);
            if (it % mid > 0)
            {
                store++;
            }

            if (store > n)
                return 0;
        }

        return store <= n;
    }

public:
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());

        int ans = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (isPossible(n, quantities, mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};

int main()
{

    return 0;
}