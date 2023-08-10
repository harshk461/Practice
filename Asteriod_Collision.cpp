#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> s;
        int n = asteroids.size();
        for (int i = 0; i < n; i++)
        {
            if (asteroids[i] > 0 || s.empty() || s.back() < 0)
                s.push_back(asteroids[i]);
            else if (s.back() <= -asteroids[i])
            {
                if (s.back() < -asteroids[i])
                    i--;
                s.pop_back();
            }
        }
        return s;
    }
};

int main()
{

    return 0;
}