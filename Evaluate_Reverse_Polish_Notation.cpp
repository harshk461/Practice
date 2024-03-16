#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        int ans = 0;

        for (auto it : tokens)
        {
            if (it.size() > 1 || isdigit(it[0]))
                st.push(stoi(it));
            else
            {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                if (it == "+")
                    st.push(op1 + op2);
                if (it == "-")
                    st.push(op1 - op2);
                if (it == "*")
                    st.push(op1 * op2);
                if (it == "/")
                    st.push(op1 / op2);
            }
        }

        return st.top();
    }
};

int main()
{

    return 0;
}