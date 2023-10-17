#include <bits/stdc++.h>
using namespace std;

class MountainArray
{
public:
    int get(int index){};
    int length(){};
};

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int length = mountainArr.length();

        // find index of peak element
        int low = 1;
        int high = length - 2;
        while (low != high)
        {
            int testindex = low + (high - low) / 2;
            if (mountainArr.get(testindex) < mountainArr.get(testindex + 1))
                low = testindex + 1;
            else
                high = testindex;
        }

        int peakIndex = low;

        // BS in increasing part
        low = 0;
        high = peakIndex;
        while (low != high)
        {
            int testIndex = (low + high) / 2;
            if (mountainArr.get(testIndex) < target)
                low = testIndex + 1;
            else
                high = testIndex;
        }
        if (mountainArr.get(low) == target)
            return low;

        // BS in decreasing part
        low = peakIndex + 1;
        high = length - 1;
        while (low != high)
        {
            int testIndex = (low + high) / 2;
            if (mountainArr.get(testIndex) > target)
                low = testIndex + 1;
            else
                high = testIndex;
        }

        if (mountainArr.get(low) == target)
            return low;

        return -1;
    }
};

int main()
{

    return 0;
}