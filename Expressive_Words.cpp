class Solution
{
private:
    bool isValid(string s, string word)
    {
        int m = s.length();
        int n = word.length();
        int i = 0, j = 0;

        while (i < m && j < n)
        {
            char ch = word[j];
            if (s[i] != ch)
                return false;
            else
            {
                int lenS = 0;
                int lenW = 0;

                // length of repeating character in string s
                while (i < m && s[i] == ch)
                    lenS++, i++;

                // length of repeating character in string s
                while (j < n && word[j] == ch)
                    lenW++, j++;

                if ((lenS < lenW) || (lenS != lenW && lenS < 3))
                    return false;
                else
                    continue;
            }
        }

        return (i == m && j == n);
    }

public:
    int expressiveWords(string s, vector<string> &words)
    {
        int count = 0;
        for (auto word : words)
            if (isValid(s, word))
                count++;

        return count;
    }
};