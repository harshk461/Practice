#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        arr[0] = 1;

        for (int i = 1; i < arr.size(); i++)
        {
            if (abs(arr[i] - arr[i - 1]) <= 1)
                continue;
            else
                arr[i] = arr[i - 1] + 1;
        }

        return arr.back();
    }

public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        int count = 1;

        sort(arr.begin(), arr.end());

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] >= ans + 1)
                ans++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}