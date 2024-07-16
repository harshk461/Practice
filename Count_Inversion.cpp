#include <bits/stdc++.h>
using namespace std;

int merge(int low, int high, int mid, vector<int> &arr)
{

    int count = 0;
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        // right is smaller
        else
        {
            count += (mid - left + 1);
            temp.push_back(arr[right]);
            right++;
        }
    }

    // remaining elements
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    return count;
}

int mergeSort(int l, int h, vector<int> &arr)
{
    int count = 0;
    if (l >= h)
        return count;

    int mid = (l + h) / 2;
    count += mergeSort(l, mid, arr);
    count += mergeSort(mid + 1, h, arr);

    count += merge(l, h, mid, arr);

    return count;
}

int countInversion(vector<int> &arr)
{
    return mergeSort(0, arr.size() - 1, arr);
}

int main()
{

    return 0;
}