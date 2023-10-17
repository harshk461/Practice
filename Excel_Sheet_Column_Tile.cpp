#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans = "";
        while (columnNumber > 0)
        {
            columnNumber -= 1;
            ans += (columnNumber % 26) + '0';
            columnNumber /= 26;
        }
        return ans;
    }
};

int main()
{

    return 0;
}