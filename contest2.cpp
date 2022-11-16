// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         double n;
//         cin >> n;
//         if ((fmod(n, 2)) != 0)
//             cout << "No" << endl;
//         else
//             cout << "Yes" << endl;
//     }
//     return 0;
// }
// #include <iostream>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int a, b;
//         cin >> a >> b;
//         int sum = a + b;
//         bool is_prime = true;
//         if (sum == 0 || sum == 1)
//         {
//             is_prime = false;
//         }
//         for (int i = 2; i <= sum / 2; ++i)
//         {
//             if (sum % i == 0)
//             {
//                 is_prime = false;
//                 break;
//             }
//         }
//         if (is_prime)
//             cout << "Alice" << endl;
//         else
//             cout << "Bob" << endl;
//     }
//     return 0;
// }

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
//         int arr[1000];
//         for (int i = 0; i < 2 * n; i++)
//         {
//             cin >> arr[i];
//         }
//         sort(arr, arr + n);
//         for (int i = 0; i < 2 * n; i++)
//             cout << arr[i] << " ";
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// long long count(vector<int> arr, int n, int size)
// {
//     long long count = 0;
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == n)
//             count++;
//     }
//     return count;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vector<int> arr;
//         for (int i = 0; i < 2 * n; i++)
//         {
//             int element;
//             cin >> element;
//             arr.push_back(element);
//         }
//         int flag = 0;
//         for (int i = 0; i < 2 * n; i++)
//         {
//             if (count(arr, arr[i], 2 * n) > 2)
//             {
//                 cout << "No" << endl;
//                 flag = 1;
//                 break;
//             }
//             flag = 0;
//         }
//         if (flag == 0)
//             cout << "Yes" << endl;
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
        int n, k;
        cin >> n >> k;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            arr.push_back(ele);
        }
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == k)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1 && arr[n - 1] != k)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
