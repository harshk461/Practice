#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int passThePillow(int n, int time)
    {
        bool flag = true;
        int N = 1;
        for (int i = 0; i < time; i++)
        {
            // forward direction
            if (flag)
            {
                if (N == n)
                    flag = false;
                else
                    N++;
            }
            else
            {
                if (N == 0)
                    flag = true;
                else
                    N--;
            }
        }

        return N;
    }
};

int main()
{

    return 0;
}