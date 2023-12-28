#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> arr = {0, 0, 0};
    for (auto it : s)
        if (it != '+')
            arr[it - '0' - 1]++;

    string ans = "";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            ans += ((i + 1) + '0');
            ans.push_back('+');
        }
    }
    cout << ans.substr(0, s.length()) << endl;
    return 0;
}