#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        int n = words.size();
        unordered_map<char, int> map;
        for (auto word : words)
            for (auto it : word)
                map[it]++;

        for (auto it : map)
            if (it.second % n != 0)
                return false;

        return true;
    }
};

int main()
{

    return 0;
}