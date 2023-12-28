#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;

        string temp = goal + goal;
        return temp.find(s) != string::npos;
    }

public:
    bool
    rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;

        for (int i = 0; i < goal.length(); i++)
        {
            bool rotatePos = true;
            for (int j = 0; j < s.length(); j++)
            {
                if (goal[(i + j) % goal.length()] != s[j])
                {
                    rotatePos = true;
                    break;
                }
            }
            if (rotatePos)
                return true;
        }
        return false;
    }
};

int main()
{

    return 0;
}