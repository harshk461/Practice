#include <bits/stdc++.h>
void reverseArray(vector<int> &arr, int m)
{
    // Write your code here.
    int len = arr.size();
    int left = m + 1, right = len - 1;
    while (left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}
void printArray(vector<int> arr, int m)
{
    for (int i = 0; i < m; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int m = 4;
    reverseArray(&arr, m);
}