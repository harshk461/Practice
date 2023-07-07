#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string ans;
        while (i >= 0 ||  j >= 0 || carry)
        {
            if (i >= 0)
                carry += num1[i--] - '0';
            if (j >= 0)
                carry += num2[j--] - '0';
            ans += carry % 10 + '0';
            carry /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}