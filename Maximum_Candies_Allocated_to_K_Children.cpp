#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int count(int mid, vector<int> &arr)
    {
        int ans = 0;
        for (auto it : arr)
        {
            ans += (it / mid);
        }
        return ans;
    }

public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        int maxi = max_element(candies.begin(), candies.end());
        int mini = min_element(candies.begin(), candies.end());

        int low = mini;
        int high = maxi;

        int mid = (low + high) / 2;
        while (low < high)
        {
            if (count(mid, candies) < k)
                low = mid - 1;
            else
                high = mid;
            mid = (low + high) / 2;
        }

        return mid;
    }
};

int main()
{

    return 0;
}