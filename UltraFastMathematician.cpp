#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A, B;
    cin >> A;
    cin >> B;
    string result = "";
    int res;
    int range = A.length();
    for (int i = 0; i < range; i++)
    {
        char a = A[i];
        char b = B[i];
        if ((a == '1' && b == '0') || (a == '0' && b == '1'))
        {
            result += '1';
        }
        else
        {
            result += '0';
        }
    }
    cout << result << endl;

    return 0;
}