#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int n = bills.size();
        int five = 0, tens = 0, twenty = 0;
        for (int i = 0; i < n; i++)
        {
            if (bills[i] == 5)
                five++;
            else if (bills[i] == 10)
            {
                tens++;
                if (five > 0)
                    five--;
                else
                    return false;
            }
            else
            {
                twenty++;
                if (tens > 0 && five > 0)
                    tens--, five--;
                else if (five > 2)
                    five -= 3;
                else
                    return false;
            }
        }
    }
};

int main()
{

    return 0;
}