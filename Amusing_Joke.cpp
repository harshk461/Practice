#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    sort(s3.begin(), s3.end());

    string temp = s1 + s2;
    sort(temp.begin(), temp.end());
    if (temp.length() > s3.length() || s3.length() > temp.length())
        cout << "NO" << endl;
    else
    {
        bool ans = false;
        for (int i = 0; i < temp.length(); i++)
            if (temp[i] != s3[i])
                ans = true;

        if (ans)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}