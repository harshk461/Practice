#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int find(int a, int b)
    {
        a %= 1337;
        int res = 1;
        for (int i = 0; i < b; i++)
        {
            res *= a;
            res %= 1337;
        }
        return res;
    }

    int solve(int a, vector<int> &b)
    {
        int sum = 0;
        for (int i = 0; i < b.size(); i++)
            sum = (sum % 10 + b[i]);
        sum %= 1337;

        int power = 1;
        for (int i = 1; i <= sum)
            power = (power * a) % 1337;

        return power % 1337;
    }

public:
    int superPow(int a, vector<int> &b)
    {
        int res = 1;
        int x, f;
        for (int i = 0; i < b.size(); i++)
        {
            x = find(a, b[i]);
            x *= res;
            x %= 1337;
            f = x;
            x = find(x, 10);
            res = x;
        }
        return solve(a, b);
    }
};

int main()
{
    vector<int> b = {4, 3};
    Solution s;
    s.superPow(2, b);
    return 0;
}