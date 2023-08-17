#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int containOne(int n)
    {
        string temp = to_string(n);
        int count = 0;
        if (temp.find('1') < temp.length())
            for (auto i : temp)
                if (i == '1')
                    count++;
        return count;
    }
    int brute(int n)
    {
        if (n < 1)
            return 0;
        if (n <= 9)
            return 1;

        int count = 1;
        for (int i = 10; i <= n; i++)
            if (containOne(n) > 0)
                count += containOne;
        return count;
    }

    int brute2(int n)
    {
        if (n < 1)
            return 0;
        if (n <= 9)
            return 1;

        int ans = 1;
        for (int i = 10; i <= n; i++)
        {
            string temp = to_string(i);
            ans += count(temp.begin(), temp.end(), '1');
        }
        return ans;
    }

    int optimal(int n)
    {
        int ans = 0;
        for (long long i = 1; i <= n; i *= 10)
        {
            long long divider = i * 10;
            ans += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
        }
        return ans;
    }

public:
    int countDigitOne(int n)
    {
        return brute(n);
    }
};

int main()
{

    return 0;
}