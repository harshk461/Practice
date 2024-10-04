#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> brute(int x, int y, int bound)
    {
        set<int> ans;
        int n = log10(bound);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pow(x, i) + pow(y, i) <= bound)
                {
                    ans.insert(x);
                    ans.insert(y);
                }
            }
        }

        vector<int> res(ans.begin(), ans.end());
        return res;
    }

public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        return brute(x, y, bound);
    }
};

int main()
{

    return 0;
}