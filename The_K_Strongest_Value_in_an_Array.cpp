#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> solve(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        int median = arr[(n - 1) / 2];

        vector<int> ans;

        int i = 0, j = n - 1;
        while (k > 0)
        {
            if (abs(arr[i] - median) > abs(arr[j] - median))
            {
                ans.push_back(arr[i]);
                i++;
            }
            else
            {
                ans.push_back(arr[j]);
                j--;
            }
            k--;
        }

        return ans;
    }

public:
    vector<int> getStrongest(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        int median;
        if (n % 2 == 0)
            median = (arr[(n - 1) / 2] + arr[n / 2]) / 2;
        else
            median = arr[n / 2];

        vector<int> ans;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         if (abs(arr[i] - median))
        //     }
        // }

        return solve(arr, k);
    }
};

int main()
{

    return 0;
}