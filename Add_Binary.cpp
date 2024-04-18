#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string ans;

        while (i >= 0 || j >= 0 || carry)
        {
            if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';
            ans += carry % 2 + '0';
            carry /= 2;
        }
        a
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    string ans = s.addBinary("111", "1");
    return 0;
}