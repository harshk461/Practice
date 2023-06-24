#include <bits/stdc++.h>
using namespace std;

// use prefix sum in array

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int maxAlt = 0;
        for (int i = 0; i < gain.size(); i++)
        {
            maxAlt = max(getPrefixSum(gain, i), maxAlt);
        }
        return maxAlt;
    }

    int getPrefixSum(vector<int> arr, int end)
    {
        int sum = 0;
        for (int i = 0; i <= end; i++)
        {
            sum += arr[i];
        }
        return sum;
    }
};

int main()
{

    return 0;
}