#include <bits/stdc++.h>
using namespace std;

int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
{
    int ans = 0;
    for (auto item : items)
    {
        if (ruleKey == "color")
        {
            if (item[1] == ruleValue)
            {
                ans++;
            }
        }
        else if (ruleKey == "type")
        {
            if (item[0] == ruleValue)
            {
                ans++;
            }
        }
        else if (ruleKey == "name")
        {
            if (item[2] == ruleValue)
            {
                ans++;
            }
        }
    }
    return ans;
}
int main()
{

    return 0;
}