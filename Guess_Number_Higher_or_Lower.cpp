#include <bits/stdc++.h>
using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        int l = 1, h = n;
        int mid = l + (h - l) / 2;
        while (l < h)
        {
            if (guess(mid) == 0)
                return mid;
            if (guess(mid) == -1)
                l = h + 1;
            else
                h = l - 1;
            mid = l + (h - l) / 2;
        }
        return mid;
    }
};

int main()
{

    return 0;
}