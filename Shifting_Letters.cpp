#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string brute(string s, vector<int> &shifts)
    {
        string temp = s;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                s[j] = 'a' + ((s[j] - 'a' + shifts[i]) % 26);
            }
        }

        return s;
    }

    string solve(string s, vector<int> &shifts)
    {
        int n = s.length();
        long long totalSum = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            totalSum += shifts[i] % 26;
            int val = s[i] - 'a';
            s[i] = 'a' + (totalSum + val) % 26;
        }
        return s;
    }

public:
    string shiftingLetters(string s, vector<int> &shifts)
    {
        return solve(s, shifts);
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 2, 3};

    cout << s.shiftingLetters("aaa", arr);
    return 0;
}