#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int l = -1;
        int r = -1;
        for (int i = 0; i <= dominoes.length(); i++)
        {
            if (i == dominoes.length() || dominoes[i] == 'R')
            {
                if (l < r)
                    while (r < i)
                        dominoes[r++] = 'R';
                r = i;
            }
            else if (dominoes[i] == 'L')
            {
                if (r < l || l == -1 && r == -1)
                {
                    if (l == -1 && r == -1)
                        l++;
                    while (l < i)
                        dominoes[l++] = 'L';
                }
                else
                {
                    int l = r + 1;
                    int r = i - 1;
                    while (l < r)
                    {
                        dominoes[l++] = 'R';
                        dominoes[r--] = 'L';
                    }
                }
                l = i;
            }
        }
        return dominoes;
    }
};

int main()
{

    return 0;
}