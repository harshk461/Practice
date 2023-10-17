#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int n = customers.length();
        int currPenalty = count(customers.begin(), customers.end(), 'Y');
        int minPenalty = currPenalty;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {

            if (customers[i] == 'Y')
                currPenalty--;
            if (customers[i] == 'N')
                currPenalty++;

            if (currPenalty < minPenalty)
            {
                ans = i + 1;
                minPenalty = currPenalty
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.bestClosingTime("YYNY");
    return 0;
}