#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int one = 0, zero = 0;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        if (element == 0)
            zero++;
        else
            one++;
    }
    if (one >= 1)
        cout << "HARD" << endl;
    else
        cout << "EASY" << endl;
    return 0;
}