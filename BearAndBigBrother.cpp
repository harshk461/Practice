#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int flag = true;
    int year = 1;
    while (flag)
    {
        a *= 3;
        b *= 2;
        if (a > b)
        {
            flag = false;
        }
        else
        {
            year++;
        }
    }
    cout << year << endl;
}