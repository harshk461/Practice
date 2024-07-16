#include <iostream>
using namespace std;

class Solution
{
public:
    int scoreOfString(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
            ans += abs((int)s[i] - (int)s[i + 1]);
        return ans;
    }
};

int main()
{

    return 0;
}