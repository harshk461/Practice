#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        int arr[100];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n, greater<int>());
        int count = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum < w)
            {
                count++;
            }
            else
            {
                count++;
                break;
            }
        }
        cout << n - count << endl;
    }
    return 0;
}
