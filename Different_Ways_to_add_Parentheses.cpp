#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    map<pair<int, int>, vector<int>> dp;
    vector<int> solve(int l, int r, string expression)
    {
        if (dp.count({l, r}))
        {
            return dp[{l, r}];
        }
        vector<int> ans;
        for (int i = l; i <= r; i++)
        {
            if (expression[i] == '+' or expression[i] == '-' or expression[i] == '*')
            {
                vector<int> left = solve(l, i - 1, expression);
                vector<int> right = solve(i + 1, r, expression);

                for (auto &num1 : left)
                {
                    for (auto &num2 : right)
                    {
                        if (expression[i] == '+')
                        {
                            ans.push_back(num1 + num2);
                        }
                        else if (expression[i] == '-')
                        {
                            ans.push_back(num1 - num2);
                        }
                        else
                        {
                            ans.push_back(num1 * num2);
                        }
                    }
                }
            }
        }
        if (ans.empty())
        {
            ans.push_back(stoi(expression.substr(l, r - l + 1)));
        }
        return dp[{l, r}] = ans;
    }

public:
    vector<int> diffWaysToCompute(string expression)
    {
        return solve(expression, 0, expression.length() - 1);
    }
};

int main()
{
    Solution s;
    s.diffWaysToCompute("2*3-4*5");

    return 0;
}