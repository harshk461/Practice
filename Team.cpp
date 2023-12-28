#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    while (n > 0)
    {
        vector<int> temp(3, 0);
        for (int i = 0; i < 3; i++)
            cin >> temp[i];

        int c = count(temp.begin(), temp.end(), 1);
        if (c >= 2)
            ans++;
        n--;
    }
    cout << ans;

    return 0;
}