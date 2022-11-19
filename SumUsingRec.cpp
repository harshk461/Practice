#include <bits/stdc++.h>
using namespace std;

int SumArray(int *arr, int size)
{
    // base case
    if (size <= 0)
    {
        return 0;
    }

    return (SumArray(arr, size - 1) + arr[size - 1]);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;

    int ans = SumArray(arr, size);
    cout << ans << endl;
}