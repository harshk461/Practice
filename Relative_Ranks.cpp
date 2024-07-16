#include <iostream>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        vector<string> ans(n);
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
            map[score[i]] = i;

        vector<int> v = score;

        sort(v.begin(), v.end(), greater<int>());

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                ans[map[v[i]]] = "Gold Medal";
            else if (i == 1)
                ans[map[v[i]]] = "Silver Medal";
            else if (i == 2)
                ans[map[v[i]]] = "Bronze Medal";
            else
                ans[map[v[i]]] = to_string(i + 1);
        }

        return ans;
    }
};

int main()
{

    return 0;
}