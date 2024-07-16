#include <iostream>
using namespace std;

class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        int n = word.length();

        map<int, int> freq;
        freq[0] = 1;

        int mask = 0;
        long res = 0L;
        for (int i = 0; i < n; i++)
        {
            char c = word[i];
            int bit = c - 'a';

            mask ^= (1 << bit);

            res += freq[mask];

            for (int j = 0; j < 10; j++)
                res += freq[mask ^ (1 << j)];

            freq[mask]++;
        }
        return res;
    }
};

int main()
{

    return 0;
}