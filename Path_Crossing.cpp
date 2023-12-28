#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPathCrossing(string path)
    {
        vector<int> p = {0, 0};
        unordered_map<char, vector<int>> map;
        set<vector<int>> visited;

        map['N'] = {0, 1};
        map['S'] = {0, -1};
        map['E'] = {1, 0};
        map['W'] = {-1, 0};

        for (auto it : path)
        {
            p[0] += map[it][0], p[1] += map[it][1];
            vector<int> temp = p;
            if (visited.count(temp) > 1)
                return true;
            visited.insert(temp)
        }
        return false;
    }
};

int main()
{
    Solution s;
    s.isPathCrossing("NNSWWEWSSESSWENNW");
    return 0;
}