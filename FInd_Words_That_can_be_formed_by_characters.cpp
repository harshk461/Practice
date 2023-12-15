#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        unordered_map<char, int> map;
        for (auto c : chars)
            map[c]++;

        int ans = 0;
        for (auto word : words)
        {
            unordered_map<char, int> count;
            for (auto c : word)
                count[c]++;

            bool good = true;
            for (auto it : count)
            {
                if (map[it.first] < it.second)
                {
                    good = false;
                    break;
                }
            }

            if (good)
                ans += word.size();
        }
        return ans;
    }
};

int main()
{

    return 0;
}