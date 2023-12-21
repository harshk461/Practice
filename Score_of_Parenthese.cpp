#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(string s)
    {
        stack<int> st;
        int ans = 0;
        for (auto it : s)
        {
            if (it == '(')
            {
                st.push(ans);
                ans = 0;
            }
            else
            {
                ans += st.top() + max(ans, 1);
                st.pop();
            }
        }
        return ans;
    }

public:
    int i = 0;
    int scoreOfParentheses(string s)
    {
        int score = 0;
        while (i < s.length())
        {
            char temp = s[i];
            i++;
            if (temp == '(')
            {
                if (s[i] == ')')
                {
                    score++;
                    i++
                }
                else
                    score += 2 * scoreOfParentheses(s);
            }
            else if (temp == ')')
                return score;
        }
        return score;
    }
};

int main()
{

    return 0;
}