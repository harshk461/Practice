#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<pair<int, int>> st; // store value and min at that time
    int mini = INT_MAX;

    void push(int x)
    {
        if (st.empty())
            st.emplace(x, x);
        else
            st.emplace(x, min(x, st.top().second));
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

int main()
{

    return 0;
}