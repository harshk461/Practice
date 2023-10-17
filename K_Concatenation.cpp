#include <bits/stdc++.h>
using namespace std;

int maxSubarray(vector<int> nums)
{
    int n = nums.size();
    long long sum = 0, maxi = LONG_MIN;
    // int ansS = -1, ansE = -1;
    // int start = 0;
    for (int i = 0; i < n; i++)
    {
        // if (sum == 0)
            // start = i;
        sum += nums[i];

        if (sum > maxi)
        {
            // ansS = start, ansE = i;
            maxi = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        vector<int> b;
        while (n--)
        {
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        while (k--)
        {
            for (auto i : a)
                b.push_back(i);
        }
        cout << maxSubarray(b);
    }
    return 0;
}