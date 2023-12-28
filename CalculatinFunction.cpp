#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    if (n % 2 == 0)
    {
        int even = (n / 2) * (n / 2 + 1);
        int odd = (n * n) / 4;
        odd *= -1;
        cout << even + odd << endl;
    }
    else
    {
        int even = (n / 2) * (n / 2 + 1);
        int odd = ((n / 2) + 1) * (n / 2 - 1);
        odd *= -1;
        cout << even + odd << endl;
    }

    return 0;
}