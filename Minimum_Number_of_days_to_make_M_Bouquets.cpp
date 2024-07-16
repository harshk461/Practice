#include <bits/stdc++.h>
using namespace std;
// koko need banana ke type ka question h
class Solution
{
private:
    int solveAtDayMid(vector<int> &arr, int day, int k)
    {
        int num = 0;
        int count = 0;
        int n = arr.size();
        // check number of bouquet can be made on that day
        // because if day is 10 then all the flower before day 10 then all the flowers are already bloomed
        for (int i = 0; i < n; i++)
        {
            // if day is same then increase the current flower count
            if (arr[i] <= day)
                count++;
            // restart the flower count
            else
                count = 0;

            // if count is equal to size of bouquet size then increase the number of bouquets
            // and reset the count of flower
            if (count == k)
            {
                num++;
                count = 0;
            }
        }
        return num;
    }

public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if (m > n / k)
            return -1;

        int s = 0;
        int e = 0;
        for (auto day : bloomDay)
            e = max(e, day);

        int ans = 0;

        while (s <= e)
        {
            // check every mid that on that day we can complete the bouquet or not
            int mid = s + (e - s) / 2;

            // if count of bouquet is greater than need that decrease the range from start to mid
            if (solveAtDayMid(bloomDay, mid, k) >= m)
            {
                ans = mid;
                e = mid - 1;
            }
            // other wise shift range to mid to end
            else
            {
                s = mid + 1;
            }
        }

        return ans;
    }
};