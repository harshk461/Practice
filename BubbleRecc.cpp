#include <bits/stdc++.h>
using namespace std;

void sortArray(int *arr, int n)
{
    // base case-already sorted
    if (n == 0 || n == 1)
        return;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
    sortArray(arr, n - 1);
}

int main()
{
    int arr[6] = {1, 5, 3, 2, 9, 0};
    int n = 6;
    sortArray(arr, n);
    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}