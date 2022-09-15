#include <iostream>
using namespace std;

int main()
{
    int inp;
    cin >> inp;

    if (inp % 2 == 0 && inp > 2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}