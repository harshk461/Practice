#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class CustomStack
{
public:
    stack<int> main;
    stack<int> temp;
    int size;
    CustomStack(int maxSize)
    {
        this->size = maxSize;
    }

    void push(int x)
    {
        if (main.size() + 1 <= size)
        {
            main.push(x);
        }
    }

    int pop()
    {
        if (!main.empty())
        {
            int ans = main.top();
            main.pop();
            return ans;
        }
        else
            return -1;
    }

    void increment(int k, int val)
    {
        int n = main.size();
        // push n-k elements
        int t = n - k;
        while (t-- > 0)
        {
            int top = main.top();
            main.pop();

            temp.push(top);
        }

        // increment K elements
        while (k > 0 && k < main.size())
        {
            int top = main.top();
            main.pop();

            temp.push(top + val);
            k--;
        }

        while (!temp.empty())
        {
            int top = temp.top();
            temp.pop();

            main.push(top);
        }
    }
};

int main()
{

    return 0;
}