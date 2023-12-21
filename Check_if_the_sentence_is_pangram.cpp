#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        set<char> s;
        for (auto it : sentence)
        {
            s.insert(it);
            if (s.size() == 26)
                return true;
        }
        return false;
    }
};

int main()
{

    return 0;
}