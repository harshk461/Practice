#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int getHours(vector<int> &piles, int hour)
    {
        int total = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++)
            total += ceil((double)piles[i] / (double)hour);
        return total;
    }

public:
    // TC-O(NLog(max(Element)))
    int minEatingSpeed(vector<int> &piles, int hour)
    {
        int l = 1;
        int h = max_element(piles.begin(), piles.end());

        while (l <= h)
        {
            int m = l + (h - l) / 2;
            int total = getHours(piles, m);
            if (total <= hour)
            {
                h = m - 1;
            }

            else
                l = m + 1;
        }
        return l;
    }
};

int main()
{

    return 0;
}