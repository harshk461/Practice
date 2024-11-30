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
    char evaluate(char op, vector<char> &vals)
    {
        // NOT case
        if (op == '!')
            return vals[0] == 't' ? 'f' : 't';

        // AND
        if (op == '&')
        {
            for (auto ch : vals)
            {
                if (ch == 'f')
                    return 'f';
            }
            return 't';
        }

        // OR
        if (op == '|')
        {
            for (auto ch : vals)
            {
                if (ch == 't')
                    return 't';
            }
            return 'f';
        }

        return 'f';
    }

public:
    bool parseBoolExpr(string expression)
    {
        stack<char> st;
        for (auto ch : expression)
        {
            if (ch == ')')
            {
                vector<char> values;
                // get the expression in current parentheses
                while (st.top() != '(')
                {
                    values.push_back(st.top());
                    st.pop();
                }
                // remove (
                st.pop();
                // operation
                char op = st.top();
                st.pop();

                char result = evaluate(op, values);
                st.push(result);
            }
            else if (ch != ',')
                st.push(ch);
        }

        return st.top() == 't';
    }
};

int main()
{

    return 0;
}