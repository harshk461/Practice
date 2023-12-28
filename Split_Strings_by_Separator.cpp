#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void spilt(string word, char sep, vector<string> &ans)
    {
        string temp = "";
        for (int i = 0; i <= word.length(); i++)
        {
            if ((word[i] == sep && temp != "") || (word[i] == '\0' && temp != ""))
            {
                ans.push_back(temp);
                temp = "";
            }
            else if (word[i] != sep)
                temp += word[i];
        }
    }

public:
    vector<string> splitWordsBySeparator(vector<string> &words, char separator)
    {
        vector<string> ans;
        for (auto word : words)
            spilt(word, separator, ans);

        for (auto it : ans)
            cout << it << " ";
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> arr = {"one.two.three", "four.five", "six"};
    s.splitWordsBySeparator(arr, '.');
    return 0;
}