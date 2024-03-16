#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> start;
    stack<int> end;
    MyQueue()
    {
    }

    void push(int x)
    {
        start.push(x);
    }

    int pop()
    {
        int ans = 0;
        while (start.size() != 1)
        {
            int top = start.top();
            start.pop();
            end.push(top);
        }
        ans = start.top();
        start.pop();
        while (!end.empty())
        {
            start.push(end.top());
            end.pop();
        }

        return ans;
    }

    int peek()
    {
        int ans = 0;
        while (start.size() != 1)
        {
            int top = start.top();
            start.pop();
            end.push(top);
        }
        ans = start.top();
        start.pop();
        end.push(ans);
        while (!end.empty())
        {
            start.push(end.top());
            end.pop();
        }

        return ans;
    }

    bool empty()
    {
        return start.empty();
    }
};

int main()
{

    return 0;
}