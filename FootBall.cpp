#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int back_to_back_standing = 1;
    for (int i = 1; i <= s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            back_to_back_standing++;
            if (back_to_back_standing == 7)
            {
                cout << "YES" << endl;
                break;
            }
        }
        else
            back_to_back_standing = 1;
    }
    if (back_to_back_standing < 7)
        cout << "NO" << endl;
    return 0;
}