#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_map<int, int> map;
        for (auto it : stones)
            map[it]++;
        int ans = 0;
        for (auto i : jewels)
            ans += map[i];

        return ans;
    }
};

int main()
{

    return 0;
}