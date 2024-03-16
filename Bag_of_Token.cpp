#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int score = 0;

        int n = tokens.size();
        int i = 0, j = n - 1;
        int maxi = 0;
        while (i <= j)
        {
            if (score > 0 && tokens[i] > power)
            {
                power += tokens[j];
                j--;
                score--;
            }
            else if (power >= tokens[i])
            {
                power -= tokens[i];
                score++;
                maxi = max(maxi, score);
                i++;
            }
            else
                return maxi;
        }

        return maxi;
    }
};

int main()
{

    return 0;
}