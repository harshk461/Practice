#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
        int a, b;
        cin >> a >> b;
        int sum = a + b;
        int matches = 0;
        while (sum > 0)
        {
            int rem = sum % 10;
            matches += arr[rem];
            sum /= 10;
        }
        cout << matches << endl;
    }
    return 0;
}
