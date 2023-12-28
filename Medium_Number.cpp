#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> arr = {a, b, c};
        sort(arr.begin(), arr.end());
        cout << arr[1] << endl;
    }
    return 0;
}