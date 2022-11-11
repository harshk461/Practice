#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    double vol = 0;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }
    for (int i = 0; i < n; i++)
    {
        vol += arr[i];
    }
    cout << ((vol / 100) / n) * 100;
    return 0;
}