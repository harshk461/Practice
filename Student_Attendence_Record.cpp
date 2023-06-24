#include <bits/stdc++.h>
using namespace std;

bool checkRecord(string s)
{
    int present = 0, absent = 0, late = 0, n = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'P')
        {
            present++;
            n = 0;
        }
        else if (s[i] == 'L')
        {
            late++;
            n++;
        }
        else if (s[i] == 'A')
        {
            absent++;
            n = 0;
        }

        if (n >= 3)
        {
            return false;
        }
    }
    if (absent > 2)
        return false;
    return true;
}

int main()
{
    cout << checkRecord("PPALLP") << endl;
    return 0;
}