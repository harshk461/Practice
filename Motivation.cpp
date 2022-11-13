#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int maxi = 0;
        int arr[n][2];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i][0] >> arr[i][1];
            if (arr[i][0] <= x)
            {
                if (arr[i][1] >= maxi)
                {
                    maxi = arr[i][1];
                }
            }
        }
        cout << maxi << endl;
    }
}