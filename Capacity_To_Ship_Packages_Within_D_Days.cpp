#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int check(vector<int> &arr, int mid, int days)
    {
        int ans = 0;
        int sum = 0;
        int n = arr.size();

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum > mid)
            {
                sum = arr[i];
                ans++;
            }
            else if (sum == mid)
            {
                sum = 0;
                ans++;
            }

            if (i == n - 1 && sum != 0)
                ans++;
            if (ans > days)
                break;
        }

        return ans <= days;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int mid = (low + high) / 2;

        int ans = -1;
        while (low <= high)
        {
            // is it possible to load the weights with mid amount of weight loaded every day and can load all weights within 'days' number of days
            if (check(weights, mid, days))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;

            mid = (low + high) / 2;
        }

        return ans;
    }
};

int main()
{

    return 0;
}