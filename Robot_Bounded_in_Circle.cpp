#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        unordered_map<char, pair<int, int>> dirn = {
            {'N', {0, 1}},
            {'W', {-1, 0}},
            {'S', {0, -1}},
            {'E', {1, 0}}};

        vector<int> posn = {0, 0};
        char currPosn = 'N';
        for (auto it : instructions)
        {
            if (it == 'G')
            {
                if (currPosn == 'N')
                {
                    posn[0] += dirn[currPosn].first;
                    posn[1] += dirn[currPosn].second;
                }
                else if (currPosn == 'W')
                {
                    posn[0] += dirn[currPosn].first;
                    posn[1] += dirn[currPosn].second;
                }
                else if (currPosn == 'S')
                {
                    posn[0] += dirn[currPosn].first;
                    posn[1] += dirn[currPosn].second;
                }
                else if (currPosn == 'E')
                {
                    posn[0] += dirn[currPosn].first;
                    posn[1] += dirn[currPosn].second;
                }
            }

            else if (it == 'L')
            {
                if (currPosn == 'N')
                    currPosn = 'W';
                else if (currPosn == 'W')
                    currPosn = 'S';
                else if (currPosn == 'S')
                    currPosn = 'E';
                else if (currPosn == 'E')
                    currPosn = 'N';
            }
            else if (it == 'R')
            {
                if (currPosn == 'N')
                    currPosn = 'E';
                else if (currPosn == 'W')
                    currPosn = 'N';
                else if (currPosn == 'S')
                    currPosn = 'W';
                else if (currPosn == 'E')
                    currPosn = 'S';
            }
        }

        if (posn[0] == 0 && posn[1] == 0)
            return true;

        return currPosn != 'N';
    }
};
int main()
{
    Solution s;
    s.isRobotBounded("GGLLGG");
    return 0;
}