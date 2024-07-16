#include <iostream>
using namespace std;

class Solution
{
private:
    int binaryToDecimal(string s)
    {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 1)
                ans += (s[i] * pow(2, n - 1 - i));
        }

        return ans;
    }

    void brute(int n, int steps, int &ans)
    {
        if (n == 1)
        {
            ans = max(ans, steps);
            return;
        }

        if (n % 2 == 0)
            brute(n / 2, steps + 1, ans);

        if (n % 2 != 0)
            brute(n + 1, steps + 1, ans);
    }

    void binaryAdd(string &s)
    {
        char ch = '1';
        int n = s.length() - 1;

        while (ch == '1' && n >= 0)
        {
            if (s[n] == '1')
                s[n] = '0';
            else
            {
                s[n] = '1';
                ch = '0';
            }
            n--;
        }

        if (ch == '1')
            s = '1' + s;
    }

    int solve(string s)
    {
        int steps = 0;
        while (s != "1")
        {
            // ODD
            if (s[s.length() - 1] == '1')
            {
                binaryAdd(s);
            }
            // EVEN
            else
            {
                s = s.substr(0, s.length() - 1);
            }
            steps++;
        }
        return steps;
    }

public:
    int numSteps(string s)
    {
        int n = binaryToDecimal(s);
        int steps = 0;
        int ans = 0;

        // brute(n, steps, ans);

        return solve(s);
    }
};

int main()
{

    return 0;
}