#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(int n)
{
    if (n >= 0)
    {
        int sr = sqrt(n);

        return (sr * sr == n);
    }
    return false;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sum = accumulate(arr.begin(), arr.end(), 0);

        if (check(sum))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}