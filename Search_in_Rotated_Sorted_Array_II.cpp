#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == k)
                return true;

            if (arr[low] == arr[mid] && arr[mid] == arr[high])
            {
                low++;
                high--;
                continue;
            }

            // left part is sorted
            if (arr[low] <= arr[mide])
            {
                if (arr[low] <= k && k <= arr[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // right part is sorted
            else
            {
                if (arr[mid] <= k && k <= arr[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }

public:
    bool search(vector<int> &nums, int target)
    {
        return solve(nums, target);
    }
};

int main()
{

    return 0;
}