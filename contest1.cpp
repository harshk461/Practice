// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int arr[n];
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }
//         int x = arr[0];
//         for (int i = 1; i < n; i++)
//         {
//             x = __gcd(x, arr[i]);
//         }
//         int count = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (arr[i] != x)
//             {
//                 count++;
//             }
//         }
//         cout << count << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        vector<int> arr;

        int c = 2;
        while (B > 1)
        {
            if (B % c == 0)
            {
                arr.push_back(c);
                B /= c;
            }
            else
                c++;
        }
        int count = 0;
        set<int> s(arr.begin(), arr.end());
        for (auto i : s)
        {
            if (A % i == 0)
                count++;
        }
        if (count == s.size())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
