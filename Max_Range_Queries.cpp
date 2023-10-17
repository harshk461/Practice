#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> map;
        int maxLen = INT_MIN;
        while (n--)
        {
            int l, r;
            cin >> l >> r;
            maxLen = max(maxLen, r);
            map.push_back(make_pair(l, r));
        }
        vector<int> ans(maxLen, 0);
        int currSkip = 0;
        int result = INT_MIN;
        for (auto arr : map)
        {
            for (int i = arr.first; i <= arr.second; i++)
            {
                ans[i]++;
            }
        }
        for (auto i : ans)
            cout << i << " ";
    }
    return 0;
}