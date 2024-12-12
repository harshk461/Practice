#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minChanges(string s)
    {
        vector<string> block;
        for (int i = 0; i < s.length(); i += 2)
        {
            string temp = s.substr(i, i + 2);
            block.push_back(temp);
        }

        for (auto it : block)
            cout << it << " "
;
        return 2;
    }
};


int main()
{

    return 0;
}