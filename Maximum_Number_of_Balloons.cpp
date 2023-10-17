#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int ans = INT_MAX;
        unordered_map<char, int> umap;
        umap['b'] = 0;
        umap['a'] = 0;
        umap['l'] = 0;
        umap['o'] = 0;
        umap['n'] = 0;
        for (char ch : text)
        {
            if (umap.count(ch))
                umap[ch]++;
        }
        umap['l'] /= 2;
        umap['o'] /= 2;
        for (auto v : umap)
            ans = min(ans, v.second);
        return ans;
    }
};
int main()
{

    return 0;
}