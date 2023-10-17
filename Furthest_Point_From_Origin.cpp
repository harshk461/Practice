#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(string moves)
    {
        int n = moves.length();
        int pos = 0;
        int count = 0;

        for (auto c : moves)
        {
            if (c == 'L')
                pos--;
            else if (c == 'R')
                pos++;
            else
                count++;
        }
        return abs(0 + pos) + count;
    }

public:
    int furthestDistanceFromOrigin(string moves)
    {
        unordered_map<char, int> map;
        map['L'] = 0;
        map['R'] = 0;
        map['_'] = 0;
        for (auto c : moves)
            map[c]++;

        int ans = (0 + map['R'] - map['L']);
        if (map['L'] >= map['R'])
            ans -= map['_'];
        else
            ans += map['_'];
        ans = abs(ans);
        return ans;
    }
};

int main()
{
    Solution s;
    s.furthestDistanceFromOrigin("L_RL__R");
    return 0;
}