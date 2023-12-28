#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string ans = "I hate ";
    int i = 2;
    while (i <= n)
    {
        ans += "that ";
        if (i % 2 == 0)
            ans += "I love ";
        if (i % 2 != 0)
            ans += "I hate ";
        i++;
    }
    ans += "it";
    cout << ans;
    return 0;
}