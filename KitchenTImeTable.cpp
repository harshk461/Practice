#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int j = 0; j < n; j++)
        {
            cin >> b[j];
        }
        int _time = 0;
        int count = 0;
        for (int k = 1; k <= n; k++)
        {
            cout << _time << endl;
            if (_time <= b[k - 1])
            {
                count++;
            }
            _time += (a[k] - a[k - 1]);
        }
        cout << count << endl;
    }
    return 0;
}
