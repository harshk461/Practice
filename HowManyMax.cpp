#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        ll count = 1;
        for (ll i = 0; i < n - 1; i++)
        {
            if (s[i - 1] == '1' && s[i] == '0')
                count++;
        }
        cout << count << endl;
    }
}