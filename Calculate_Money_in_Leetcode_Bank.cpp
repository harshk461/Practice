#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalMoney(int n)
    {
        int numberOfWeeks = n / 7;
        int remaining_days = n % 7;
        int start = 1;
        int total = 0;
        while (numberOfWeeks > 0)
        {
            total += (7 * (start + 7 + start - 1)) / 2;
            numberOfWeeks--;
            start++;
        }

        total += (7 * (start + remaining_days + start - 1)) / 2;
        return total;
    }
};

int main()
{

    return 0;
}