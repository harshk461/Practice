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
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int element;
            cin >> element;
            arr.push_back(element);
        }
        sort(arr.begin(), arr.end());
        int first = arr[0];
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (first == arr[i])
            {
                count++;
            }
        }
        int count2 = 1;
        for (int i = 1; i < n; i++)
        {
            if (first < arr[i])
            {
                count2++;
            }
        }

        if (count2 == n || n == 1)
        {
            cout << "Yes" << endl;
        }
        if (count == n)
        {
            cout << "No" << endl;
        }
    }
    return 0;
}