#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(string word1, string word2)
    {
        if (word1.length() != word2.length())
            return false;

        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for (int i = 0; i < word1.size(); i++)
        {
            map1[word1[i]]++;
            map2[word2[i]]++;
        }

        for (int i = 0; i < word1.length(); i++)
        {
            if (map1[word2[i]] == 0)
                return false;
            if (map2[word1[i]] == 0)
                return false;
        }

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        for (int i = 0; i < word1.length(); i++)
        {
            count1[word1[i] - 'a']++;
            count2[word2[i] - 'a']++;
        }
        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());

        if (count1 != count2)
            return false;

        return true;
    }

public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.length() != word2.length())
            return false;

        set<char> s1;
        set<char> s2;

        for (int i = 0; i < word1.length(); i++)
        {
            s1.insert(word1[i]);
            s2.insert(word2[i]);
        }

        // check if both words contain same letters
        if (s1 != s2)
            return false;

        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());

        // these array stores the count of each letter and after sorting if they both are equal it means the are close

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        for (int i = 0; i < word1.length(); i++)
        {
            count1[word1[i] - 'a']++;
            count2[word2[i] - 'a']++;
        }
        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());

        if (count1 != count2)
            return false;

        return true;
    }
};

int main()
{

    return 0;
}