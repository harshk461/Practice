#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // TLE Brute Force
    bool isUnique(int n)
    {
        string s = to_string(n);
        int n = s.length();
        set<char> s;
        for (auto i : s)
            s.insert(i);
        return n == s.size();
    }
    int solve(int n)
    {
        int last = pow(10, n);
        int count = 0;
        for (int i = 0; i <= last; i++)
            if (isUnique(i))
                count++;
        return count;
    }

    int fact(int n)
    {
        if (n == 0)
            return 1;
        return n * fact(n - 1);
    }

    int solve2(int n)
    {
        if (n > 10)
            return 0;
        return (9 * fact(9) / fact(10 - n));
    }

    int f(int n)
    {
        if (n == 0)
            return 1;

        int ans = 10;
        int unique = 9;
        for (int i = 9; n > 1 && i > 0; n--, i--)
        {
            unique *= i;
            ans += unique;
        }

        return ans;
    }

public:
    int countNumbersWithUniqueDigits(int n)
    {
        return solve(n);
    }
};

int main()
{

    return 0;
}