#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int> map;
    for (int i = 0; i < n; i++)
        map[arr[i]] = i + 1;

    for (auto it : map)
        cout << it.second << " ";

    return 0;
}