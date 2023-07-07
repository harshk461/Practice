#include <bits/stdc++.h>
using namespace std;

class TextEditor
{
private:
    string s;
    stack<string> stack;

public:
    void addText(string text)
    {
        s += text;
    }

    int deleteText(int k)
    {
        int numDel = min(k, static_cast<int>(s.length()));
        for (int i = 0; i < numDel; i++)
        {
            s.pop_back();
        }
        return numDel;
    }

    string cursorLeft(int k)
    {
        while (!s.empty() && k--)
        {
            stack.push(s.back();
            s.pop_back();
        }
        return getString();
    }

    string cursorRight(int k)
    {
        while (!stack.empty() && k--)
        {
            s += stack.top();
            stack.pop();
        }
        return getString();
    }

    string getString()
    {
        if (s.length < 10)
            return s;
        return s.substr(s.length() - 10);
    }
};

int main()
{

    return 0;
}