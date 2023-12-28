#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num <= 0)
            return false;

        int sum = 0;
        for (int i = 1; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                sum += i;
                if (i * i != num)
                    sum += num / i;
            }
        }
        return num == sum;
    }
};

int main()
{
    Solution s;
    s.checkPerfectNumber(7);
    return 0;
}