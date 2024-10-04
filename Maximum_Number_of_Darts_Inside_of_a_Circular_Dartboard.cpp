#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    bool check(int x, int y, int r)
    {
        if (pow(x, 2) + pow(y, 2) <= pow(r, 2))
            return true;
        return false;
    }

public:
    int numPoints(vector<vector<int>> &darts, int r)
    {
        int count = 0;
        for (auto it : darts)
        {
            if (check(it[0], it[1], r))
                count++;
        }
        return count;
    }
};

int main()
{

    return 0;
}