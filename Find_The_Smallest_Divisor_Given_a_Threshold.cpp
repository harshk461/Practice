#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int check(vector<int> &arr, int mid)
    {
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            ans += ceil((double)arr[i] / (double)mid);
        }

        return ans;
    }

public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        int mid = (low + high) / 2;
        int ans = -1;
        while (low <= high)
        {
            int th = check(nums, mid);
            // cout<<mid<<"->"<<th<<endl;
            if (th <= threshold)
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