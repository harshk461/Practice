#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        vector<vector<char>> dp(numRows, vector<char>(s.length() + 1,''));
        int i = 0;
        int row = 0;
        while (i < s.length())
        {
            if (row >= numRows)
                row = 0;

            if (i % 2 != 0)
            {
                dp[]
            }
        }
    }
};

int main()
{

    return 0;
}