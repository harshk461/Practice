#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// private:
//     int solve(int i, vector<int> &heights, int bricks, int ladders, vector<vector<int>> &dp)
//     {
//         int n = heights.size();

//         if (i == n - 1)
//             return 0;

//         if (bricks == 0 && ladders == 0 && heights[i + 1] > heights[i])
//             return 0;

//         if (dp[bricks][ladders] != -1)
//             return dp[bricks][ladders];

//         if (heights[i + 1] <= heights[i])
//             return 1 + solve(i + 1, heights, bricks, ladders, dp);

//         int byBrick = 0;
//         int byLadder = 0;

//         if (heights[i + 1] - heights[i] <= bricks)
//             byBrick = 1 + solve(i + 1, heights, bricks - (heights[i + 1] - heights[i]), ladders, dp);

//         if (ladders > 0)
//             byLadder = 1 + solve(i + 1, heights, bricks, ladders - 1, dp);

//         return dp[bricks][ladders] = (byBrick, byLadder);
//     }

// public:
//     int furthestBuilding(vector<int> &heights, int bricks, int ladders)
//     {
//         vector<vector<int>> dp(bricks + 1, vector<int>(ladders + 1, -1));
//         return solve(0, heights, bricks, ladders, dp);
//     }
// };

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();

        if (n == 1)
            return 0;

        priority_queue<int> pq;
        int i = 0;
        for (; i < n - 1; i++)
        {
            if (heights[i + 1] <= heights[i])
                continue;

            int diff = heights[i + 1] - heights[i];

            if (bricks >= diff)
            {
                bricks -= diff;
                pq.push(diff);
            }
            else if (ladders > 0)
            {
                if (!pq.empty())
                {
                    int top = pq.top(); // bricks difference
                    if (top > diff)
                    {
                        bricks += top;
                        pq.pop();
                        bricks -= diff;
                        pq.push(diff);
                    }
                }
                ladders--;
            }
            else
                break;
        }

        return i;
    }
};

int main()
{

    return 0;
}