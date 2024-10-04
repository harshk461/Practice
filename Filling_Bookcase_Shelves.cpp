#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, vector<vector<int>> &books, int curr_width,
              int width, int height, vector<vector<int>> &dp)
    {
        if (i >= books.size())
        {
            return height;
        }

        if (dp[i][curr_width] != -1)
            return dp[i][curr_width];
        int take = INT_MAX;    // in current level
        int notTake = INT_MAX; // skip to next level

        if (books[i][0] <= curr_width)
            // check if the new adding block have greater height than current one
            take = solve(i + 1, books, curr_width - books[i][0], width, max(height, books[i][1]), dp);

        // case go to next level and add that block
        notTake = height + solve(i + 1, books, width - books[i][0], width, books[i][1], dp);

        return dp[i][curr_width] = min(take, notTake);
    }

public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int n = books.size();
        vector<vector<int>> dp(n + 1, vector<int>(shelfWidth + 1, -1));
        return solve(0, books, shelfWidth, shelfWidth, 0, dp);
    }
};

int main()
{

    return 0;
}