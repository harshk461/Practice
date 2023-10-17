#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int index, vector<int> &arr, int n)
    {
        if (index == 1)
        {
            if (arr[1] % index == 0 && index % arr[1] == 0)
                return 1;
            return 0;
        }

        int x = arr.size();
        int count = 0;
        for (int i = 1; i <= x; i++)
        {
            if (arr[1] % index == 0 && index % arr[1] == 0)
            {
                int y = arr[i];
                arr.erase(arr.begin() + i);
                count += solve(index - 1, arr, n);
                arr.insert(arr.begin() + i, y);
            }
        }
        return count;
    }

public:
    int countArrangement(int n)
    {
        vector<int> arr(n + 1, 0);
        for (int i = 0; i <= n; i++)
            arr[i] = i;
        int x = solve(n, arr, n);
        return x;
    }
};

int main()
{

    return 0;
}