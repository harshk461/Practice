#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int brute(vector<int> &arr1, vector<int> &arr2)
    {
        int ans = 0;
        int n = arr1.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                ans = max(ans, (abs(arr1[i] - arr1[j]) + abs(arr2[i] - arr2[j]) + abs(i - j)));
        }

        return ans;
    }
    int solve(vector<int> &arr1, vector<int> &arr2)
    {
        int max1 = INT_MIN;
        int min1 = INT_MAX;

        int max2 = INT_MIN;
        int min2 = INT_MAX;

        int max3 = INT_MIN;
        int min3 = INT_MAX;

        int max4 = INT_MIN;
        int min4 = INT_MAX;

        int n = arr1.size();

        for (int i = 0; i < arr1.size(); i++)
        {
            min1 = min(min1, arr1[i] + arr2[i] + i);
            min2 = min(min2, arr1[i] + arr2[i] - i);
            min3 = min(min3, arr1[i] - arr2[i] + i);
            min4 = min(min4, arr1[i] - arr2[i] - i);
            max1 = max(max1, arr1[i] + arr2[i] + i);
            max2 = max(max2, arr1[i] + arr2[i] - i);
            max3 = max(max3, arr1[i] - arr2[i] + i);
            max4 = max(max4, arr1[i] - arr2[i] - i);
        }
        return max(max(max1 - min1, max4 - min4), max(max2 - min2, max3 - min3));
    }

public:
    int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2)
    {
        return solve(arr1, arr2);
    }
};

int main()
{

    return 0;
}