#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> temp;
        temp.push_back(arr[0]);

        for (int i = 1; i < n; i++)
        {
            if (arr[i] == temp.back())
                continue;
            else
                temp.push_back(arr[i]);
        }

        if (temp.size() == 1)
        {
            cout << "YES" << endl;
            continue;
        }

        int count = 0;
        if (temp[0] < temp[1])
            count++;
        if (temp.back() < temp[temp.size() - 2])
            count++;

        for (int i = 1; i < (temp.size() - 1) && count < 2; i++)
        {
            if (temp[i - 1] > temp[i] && temp[i] < temp[i + 1])
                count++;
        }

        cout << ((count == 1) ? "YES" : "NO") << endl;
    }
    return 0;
}