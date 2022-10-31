#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int pas;
    pas = n / 5;
    if (n % 5 > 0)
    {
        pas++;
    }
    cout << pas << endl;
}