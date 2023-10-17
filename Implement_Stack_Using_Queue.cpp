#include <bits/stdc++.h>
using namespace std;

class MyStack
{
public:
    deque<int> dq;
    MyStack()
    {
    }

    void push(int x)
    {
        dq.push_front(x);
    }

    int pop()
    {
        int temp = dq.front();
        dq.pop_front();
        return temp;
    }

    int top()
    {
        return dq.front();
    }

    bool empty()
    {
        return dq.size() == 0 ? 1 : 0;
    }
};

int main()
{

    return 0;
}