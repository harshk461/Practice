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
//         vector<int> arr(n, 0);
//         for (int i = 0; i < n; i++)
//             cin >> arr[i];

//         sort(arr.begin(), arr.end());
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i + 1; j < n; j++)
//             {
//                 if (abs(arr[i] - arr[j]) <= 1)
//                 {
//                     int temp;
//                     if (arr[i] <= arr[j])
//                         temp = i;
//                     else
//                         temp = j;
//                     arr[temp] = -1;
//                 }
//             }
//         }
//         set<int> st(arr.begin(), arr.end());
//         if (st.size() == 2 || st.size() == 1)
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
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
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int diff = 0;
        sort(arr.begin(), arr.end());
        vector<int> v;
        for (int i = 1; i < n; i++)
        {
            diff = abs(arr[i] - arr[i - 1]);
            v.push_back(diff);
        }

        sort(v.begin(), v.end(), greater<int>());

        if (v[0] > 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}

// Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    int t, n, a[55];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        sort(a, a + n);
        vector<int> v;
        int dif = 0;
        for (int i = 1; i < n; i++)
        {
            dif = abs(a[i] - a[i - 1]);
            v.push_back(dif);
        }
        sort(v.begin(), v.end(), greater<int>());
        //        for(int i=0; i<v.size(); i++){
        //            cout<<v[i]<<" ";
        //        }
        //
        //        cout<<endl;
        if (v[0] > 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}