class Solution
{
private:
    vector<string> breakSentence(string s)
    {
        vector<string> arr;
        string temp = "";
        int n = s.length();
        for (int i = 0; i <= n; i++)
        {
            if (s[i] == ' ' || i == n)
            {
                arr.push_back(temp);
                temp = "";
            }
            else
                temp += s[i];
        }

        return arr;
    }

    string correctWord(string word, vector<string> &dict)
    {
        int n = word.length();
        for (auto it : dict)
        {
            if (it.length() <= n)
            {
                int c = 0;
                for (int i = 0; i < n; i++)
                    if (word[i] == it[i])
                        c++;
                if (c == n)
                    return it;
            }
        }
        return word;
    }

    string solve(string word, vector<vector<string>> &map)
    {
        vector<string> arr = map[word[0] - 'a'];
        sort(arr.begin(), arr.end());
        for (auto it : arr)
        {
            string s = word.substr(0, it.length());
            if (s == it)
                return it;
        }

        return word;
    }

    string anotherMethod(vector<string> &dictionary, string sentence)
    {
        vector<string> words = breakSentence(sentence);
        vector<vector<string>> map(26);
        for (auto it : dictionary)
            map[it[0] - 'a'].push_back(it);

        for (int i = 0; i < words.size(); i++)
            words[i] = solve(words[i], map);

        string ans = "";
        for (int i = 0; i < words.size(); i++)
        {
            if (i < words.size() - 1)
                ans += words[i] + " ";
            else
                ans += words[i];
        }

        return ans;
    }

public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        vector<string> words = breakSentence(sentence);
        sort(dictionary.begin(), dictionary.end());
        for (int i = 0; i < words.size(); i++)
        {
            words[i] = correctWord(words[i], dictionary);
        }

        // for (auto it : words)
        //     cout << it << " ";
        // cout << endl;
        string ans = "";
        for (int i = 0; i < words.size(); i++)
        {
            if (i < words.size() - 1)
                ans += words[i] + " ";
            else
                ans += words[i];
        }

        return anotherMethod(dictionary, sentence);
    }
};
