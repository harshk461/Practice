#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
private:
    string invert_and_reverse(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
                s[i] = '0';
            else
                s[i] = '1';
        }

        reverse(s.begin(), s.end());
        return s;
    }

    char solve(int n, int k)
    {
        if (n == 1)
            return '0';

        // length of nth binary string is 2^n-1
        int length = (1 << n) - 1;
        int mid = length / 2 + 1;

        // mid char is always 1
        if (k == mid)
            return '1';

        // then we have to find char in Si-1 in the previous string
        else if (k < mid)
        {
            return solve(n - 1, k);
        }
        // else our string is present in reverse string of previous string with inverted bits
        else
        {
            char ch = solve(n - 1, length - k + 1);
            return ch == '0' ? '1' : '0';
        }
    }

public:
    char findKthBit(int n, int k)
    {
        vector<string> arr;
        arr.push_back("0");

        for (int i = 1; i < n; i++)
        {
            string prev = arr[i - 1];
            string next = prev + "1" + invert_and_reverse(prev);
        }

        for (auto it : arr)
            cout << it << " ";

        return solve(n, k);
    }
};

int main()
{

    return 0;
}