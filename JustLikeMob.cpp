#include <iostream>
using namespace std;

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, x;
        cin >> n >> m >> k >> x;
        int days = 0;
        bool flag = true;
        int year = 1;
        while (flag)
        {
            if (year % k == 0)
                days += (n + m);
            days += n;
            year++;
            if (days >= x)
            {
                flag = false;
            }
        }
        cout << year << '\t' << days << endl;
        if (year % k == 0 && (x >= (days - (n + m)) && x <= days))
        {

            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    solve();
    return 0;
}
