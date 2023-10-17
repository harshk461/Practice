#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        int curr_len = 0, start = 0, end = -1;
        for (auto str : words)
        {
            if ((end - start + 1) + curr_len + str.length() <= maxWidth)
                curr_len += str.length(), end++;
            else
            {
                // start the current line
                string sentence = words[start];
                int extraSpace = maxWidth - curr_len;
                int padding = extraSpace / max(1, end - start);

                int extra = extraSpace % max(1, end - start);

                // add words from start index+1 to end
                for (int i = start + 1; i <= end; i++)
                {
                    // add padding
                    for (j = 0; j < padding; j++)
                        sentence += " ";
                    if (extra)
                        sentence += " ", extra--;

                    sentence += words[i];
                }
                // sentence have only one word
                while (sentence.size() < maxWidth)
                    sentence += " ";
                ans.push_back(sentence);

                start = end + 1, curr_len = str.length(), end++;
            }
        }

        // handling last line
        string sentence = words[start];
        for (int i = start + 1; i <= end; i++)
            sentence += " " + words[i];
        while (sentence.length() < maxWidth)
            sentence += " ";
        ans.push_back(sentence);
        return ans;
    }
};

int main()
{

    return 0;
}