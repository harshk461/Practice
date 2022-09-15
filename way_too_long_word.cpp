#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {

        string ch;
        cin >> ch;
        if (ch.length() > 10)
        {
            int len = ch.length() - 2;

            string ans = ch[0] + to_string(len) + ch[ch.length() - 1];
            cout << ans << endl;
        }
        else
        {
            cout << ch << endl;
        }
    }
}