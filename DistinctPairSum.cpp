#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    ;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        if (l == r)
            cout << 1 << endl;
        else
            cout << 2 * (r - l) + 1 << endl;
    }
    return 0;
}
