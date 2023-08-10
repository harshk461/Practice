#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getLucky(string s, int k)
    {
        string temp;
        for (auto c : s)
            temp += to_string(c - 'a' + 1);
        int n = 0;
        for (auto ch : temp)
            n += c - '0';
        for (int i = 1; i < k; i++)
        {
            int next = 0;
            while (n)
            {
                next += n % 10;
                n /= 10;
            }
            n = next;
        }
        return n;
    }
};

int main()
{
    Solution s;
    s.getLucky("leetcode", 1);
    return 0;
}