#include <bits/stdc++.h>
using namespace std;

int findPlatform(vector<int> arr, vector<int> dep, int n)
{
    int plt = 1;
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (arr[i] >= arr[j] && dep[j] >= arr[i])
                    plt++;
            }
        }
        result = max(result, plt);
    }
    return result;
}

int main()
{

    return 0;
}