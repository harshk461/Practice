#include <bits/stdc++.h>
using namespace std;

void segregate0and1(vector<int> &arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count++;
    }
    // fill 0
    for (int i = 0; i < count; i++)
    {
        arr[i] = 0;
    }

    // fill 1
    for (int i = count; i < n; i++)
    {
        arr[i] = 1;
    }
}

// another method
void segregate0and1(vector<int> &arr, int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        while (arr[left] == 0 && left < right)
            left++;

        while (arr[right] == 1 && left < right)
            right++;

        if (left < right)
        {
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }
    }
    
}

int main()
{

    return 0;
}