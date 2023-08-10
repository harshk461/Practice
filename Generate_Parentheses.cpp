#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // private:
    //     bool isValid(string s)
    //     {
    //         stack<char> ch;
    //         int i = 0;
    //         if (s.empty())
    //         {
    //             return true;
    //         }

    //         while (i < s.length())
    //         {
    //             if (s[i] == '(' || s[i] == '{' || s[i] == '[')
    //             {
    //                 ch.push(s[i]);
    //             }
    //             else if ((s[i] == ')' && !ch.empty() && ch.top() == '(') ||
    //                      (s[i] == '}' && !ch.empty() && ch.top() == '{') ||
    //                      (s[i] == ']' && !ch.empty() && ch.top() == '['))
    //             {
    //                 ch.pop();
    //             }
    //             else
    //             {
    //                 return false;
    //             }
    //             i++;
    //         }
    //         if (ch.empty())
    //         {
    //             return true;
    //         }
    //         return false;
    //     }

    //     void solve(int n, vector<string> &ans, string temp, int open, int close)
    //     {
    //         if (temp.size() == 2 * n)
    //         {
    //             if (isValid(temp))
    //                 ans.push_back(temp);
    //             return;
    //         }

    //         if (open == n || close == n)
    //             return;

    //         // open bracket
    //         temp.push_back('(');
    //         open++;
    //         solve(n, ans, temp);
    //         open--;
    //         temp.pop_back();

    //         // close bracket
    //         temp.push_back(')');
    //         close++;
    //         solve(n, ans, temp);
    //         close--;
    //         temp.pop_back();
    //     }

    //     void solve2(int n, vector<string> &ans)
    //     {
    //         if (n == 0)
    //         {
    //             ans.push_back("");
    //             return;
    //         }

    //         for (int close = 0; close < n; close++)
    //         {
    //             for (auto left : solve(close, ans))
    //             {
    //                 for (auto right : solve(n - close - 1))
    //                 {
    //                     ans.push_back("(" + left + ")" + right);
    //                 }
    //             }
    //         }
    //     }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;

        if (n == 0)
            ans.push_back("");

        else
            for (int close = 0; close < n; close++)
                for (auto left : generateParenthesis(close))
                    for (auto right : generateParenthesis(n - close - 1))
                        ans.push_back("(" + left + ")" + right);

        return ans;
    }
};

int main()
{
    Solution s;
    s.generateParenthesis(3);
    return 0;
}