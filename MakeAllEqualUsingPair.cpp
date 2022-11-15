#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[1000];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int val = arr[0];
        for (int i = 1; i < n; i++)
        {
            val = __gcd(val, arr[i]);
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != val)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}
