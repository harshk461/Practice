#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        vector<int> arr;
        int i = 0;
        while (a > 0)
        {
            int rem = a % 10;
            if (rem != 0)
                arr.push_back(pow(10, i) * rem);
            i++;
            a /= 10;
        }
        cout << arr.size() << endl;
        for (auto it : arr)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}