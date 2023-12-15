#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        vector<string> chars = {"000", "111", "222", "333", "444", "555", "666", "777", "888", "999"};
        string ans = "";
        for (int i = 0; i < chars.size(); i++)
        {
            if (num.find(chars[i]) != std::string::npos)
                ans = max(ans, chars[i]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}