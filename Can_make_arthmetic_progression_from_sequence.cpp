#include <bits/stdc++.h>
using namespace std;

bool canMakeArithmeticProgression(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int diff = arr[1] - arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        // cout << ((arr[i] - arr[i - 1]) == diff) << " ";
        if (arr[i] - arr[i - 1] != diff)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> arr = {3, 5, 1};
    cout << canMakeArithmeticProgression(arr);
    return 0;
}