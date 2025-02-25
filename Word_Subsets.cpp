#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
private:
    vector<int> countFreq(string &word)
    {
        vector<int> count(26, 0);
        for (char c : word)
        {
            count[c - 'a']++;
        }
        return count;
    }

    bool isSubset(vector<int> &wordCount, vector<int> &maxCount)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (wordCount[i] < maxCount[i])
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<int> maxCount(26, 0);

        // Merge counts for words2
        for (string &word : words2)
        {
            vector<int> wordCount = countFreq(word);
            for (int i = 0; i < 26; ++i)
            {
                maxCount[i] = max(maxCount[i], wordCount[i]);
            }
        }

        vector<string> res;
        for (string &word : words1)
        {
            vector<int> wordCount = countFreq(word);
            if (isSubset(wordCount, maxCount))
            {
                res.push_back(word);
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}