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
        vector<int> arr(n, 0);

        int max1 = 0, max2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] >= max1)
            {
                max2 = max1;
                max1 = arr[i];
            }
            else if (arr[i] > max2)
                max2 = arr[i];
        }

        for (int i = 0; i < n; i++)
            cout << arr[i] - (arr[i] == max1 ? max2 : max1) << " ";
        cout << endl;
    }
    return 0;
}