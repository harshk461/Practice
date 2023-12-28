#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // if one->true count one otherwise zero
    int countDigit(string s, bool one)
    {
        int count = 0;
        for (auto it : s)
        {
            if (one && it == '1')
                count++;

            if (!one && it == '0')
                count++;
        }

        return count;
    }

    int solve(string s)
    {
        int ones = count(s.begin(), s.end(), '1');
        int ans = 0;
        int zeros = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
                ones--;
            else
                zeros++;
            ans = max(ans, zeros + ones);
        }
        return ans;
    }

public:
    int maxScore(string s)
    {
        int ans = 0;
        for (int i = 1; i < s.length(); i++)
        {
            string sideOne = s.substr(0, i);
            string sideTwo = s.substr(i, s.length());
            cout << countDigit(sideOne, false) << " " << countDigit(sideTwo, true) << endl;
            ans = max(ans, countDigit(sideOne, false) + countDigit(sideTwo, true));
        }
        return ans;
    }
};

int main()
{

    Solution s;
    s.maxScore("00");
    return 0;
}