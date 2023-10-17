#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int start = 1, end = num;
        long long mid = start + (end - start) / 2;
        while (start <= end)
        {
            if (mid * mid == num)
                return true;
            if (mid * mid < num)
                start = mid;
            else
                end = mid;
            mid = start + (end - start) / 2;
        }
        return false;
        // int i = 1;
        // while (i <= num)
        // {
        //     if (i * i == num)
        //         return true;
        //     i++;
        // }
        // return false;
    }
};

int main()
{

    return 0;
}