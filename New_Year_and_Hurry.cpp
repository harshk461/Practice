#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int rem_time = 240 - k;
    int i = 1;
    int time = 0;
    while (i <= n)
    {
        time += 5 * i;
        if (time > rem_time)
            break;
        ans++;
        i++;
    }
    cout << ans;
    return 0;
}