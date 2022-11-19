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
        int count = 0;
        int arr[100];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        set<int> s(arr, arr + n);
        cout << s.size() << endl;
    }
    return 0;
}
