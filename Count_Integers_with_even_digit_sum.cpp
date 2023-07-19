#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isEven(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        if (sum % 2 == 0)
            return true;
        return false;
    }

public:
    int countEven(int num)
    {
        int ans = 0;
        for (int i = 2; i <= num; i++)
        {
            if (isEven(i))
                ans++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}