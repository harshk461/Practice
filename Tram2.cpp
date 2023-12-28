#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int capacity = 0;
    int ans = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        capacity -= a;
        capacity += b;
        ans = max(ans, capacity);
    }
    cout << ans << endl;
    return 0;
}