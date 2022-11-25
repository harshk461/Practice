#include <bits/stdc++.h>
using namespace std;

int goodInteger(string str)
{
    int zero_one = 0;
    int one_zero = 0;
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] == '0' && str[i - 1] == '1')
        {
            one_zero++;
        }
        if (str[i] == '1' && str[i - 1] == '0')
        {
            zero_one++;
        }
    }
    if (zero_one == one_zero)
        return 1;
    else
        return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        long long int count = 0;
        for (long long int i = 0; i < str.size(); i++)
        {
            string temp = str;
            if (temp[i] == '0')
                temp[i] = '1';
            else if (temp[i] == '1')
                temp[i] = '0';
            count += goodInteger(temp);
        }
        cout << count << endl;
    }
    return 0;
}
