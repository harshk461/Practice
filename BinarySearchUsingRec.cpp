#include <bits/stdc++.h>
using namespace std;

bool BinarySearch(int *arr, int start, int end, int key)
{
    // base case
    if (start > end)
    {
        return false;
    }

    int mid = start + (end - start) / 2;
    if (arr[mid] == key)
    {
        return true;
    }

    if (key < arr[mid])
    {
        return BinarySearch(arr, start, mid - 1, key);
    }
    else
    {
        return BinarySearch(arr, mid + 1, end, key);
    }
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    int key = 8;
    bool ans = BinarySearch(arr, 0, size, key);
    if (ans)
        cout << "Present" << endl;
    else
        cout << "Absent" << endl;
    return 0;
}