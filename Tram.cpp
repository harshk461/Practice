#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int enter = 0;
    int exit = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        enter += a;
        exit += b;
        if (enter != 0)
        {
            enter -= exit;
        }
    }
    cout << enter << "\t" << exit << endl;
}