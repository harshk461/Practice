#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end());
        int n = deck.size();

        bool skip = false;
        int i = 0; // deck
        int j = 0; // result

        vector<int> ans(n);

        while (i < n)
        {
            if (ans[j] == 0)
            {
                if (!skip)
                {
                    ans[j] = deck[i];
                    i++;
                }
                skip = !skip;
            }

            j = (j + 1) % n;
        }
        return ans;
    }
};

int main()
{

    return 0;
}