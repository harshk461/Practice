#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> mostVisited(int n, vector<int> &rounds)
    {
        int size = rounds.size();
        vector<int> ans;

        if (rounds[0] <= rounds[size - 1])
        {
            for (int i = rounds[0]; i <= rounds[size - 1]; i++)
                ans.push_back(i);
            return ans;
        }
        else
        {
            for (int i = 1; i <= rounds[size - 1]; i++)
                ans.push_back(i);

            for (int i = rounds[0]; i <= n; i++)
                ans.push_back(i);
        }

        return ans;
    }
};

int main()
{

    return 0;
}