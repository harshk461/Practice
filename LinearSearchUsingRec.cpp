#include <bits/stdc++.h>
using namespace std;

bool isPresent(int *arr, int size, int val)
{
    // base condition
    if (size <= 0)
        return false;

    if (arr[0] == val)
        return true;

    else
    {
        bool remainingPart = isPresent(arr + 1, size - 1, val);
        return remainingPart;
    }
}

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int val = 5;
    bool ans = isPresent(arr, size, val);

    if (ans)
        cout << "Present" << endl;
    else
        cout << "absent" << endl;

    return 0;
}