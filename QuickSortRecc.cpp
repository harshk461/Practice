#include <bits/stdc++.h>
using namespace std;

int Partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;
    cout << cnt;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
            cnt++;
    }

    // place pivot at right place
    int pivotIndex = s + cnt;

    swap(arr[pivotIndex], arr[s]);

    // handling left and right part
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[i] > pivot)
            j--;

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    // parition
    int p = Partition(arr, s, e);

    // sort left side
    quickSort(arr, s, p - 1);

    // sort right side
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[5] = {3, 2, 5, 1, 7};
    int n = 5;
    quickSort(arr, 0, n - 1);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}