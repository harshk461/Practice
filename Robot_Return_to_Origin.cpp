#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        vector<int> pos = {0, 0};
        for (auto c : moves)
        {
            if (c == 'U')
                pos[1]++;
            else if (c == 'D')
                pos[1]--;
            else if (c == 'L')
                pos[0]--;
            else
                pos[0]++;
        }
        if (!pos[0] && !pos[1])
            return true;
        return false;
    }
};

int main()
{

    return 0;
}