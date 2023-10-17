#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check(vector<int> &map)
    {
        set<int> st;
        for (int i = 0; i < 26; i++)
        {
            if (map[i] == 0)
                continue;

            if (map[i] > 0)
                st.insert(map[i]);
            if (st.size() > 1)
                return false;
        }
        return true;
    }

public:
    bool equalFrequency(string word)
    {
        vector<int> map(26, 0);
        for (auto ch : word)
            map[ch - 'a']++;

        for (int i = 0; i < word.length(); i++)
        {
            map[word[i] - 'a']--;
            if (check(map))
                return true;
            map[word[i] - 'a']++;
        }
        return false;
    }
};

int main()
{

    return 0;
}