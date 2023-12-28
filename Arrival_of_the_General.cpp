#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    cin >> n >> a; // a->first element
    int mina(a), maxa(a), mini(0), maxi(0);
    for (int i = 1; i < n; i++)
    {
        cin >> a;
        if (a > maxa)
        {
            maxi = i;
            maxa = a;
        }
        if (a <= mina)
        {
            mina = a;
            mini = i;
        }
    }

    cout << maxi + (n - 1 - mini) - (mini < maxi ? 1 : 0) << endl;
    return 0;
}